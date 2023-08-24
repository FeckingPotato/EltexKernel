#include <linux/module.h>
#include <linux/configfs.h>
#include <linux/init.h>
#include <linux/tty.h>
#include <linux/kd.h>
#include <linux/console_struct.h>
#include <linux/vt_kern.h>
#include <linux/timer.h>


MODULE_DESCRIPTION("Example module illustrating the use of Keyboard LEDs.");
MODULE_LICENSE("GPL");

static struct kobject *ioKobject;

static struct timer_list my_timer;
static struct tty_driver *my_driver;

static int kbledStatus = 0;
static int blinkMode = 0;
#define BLINK_DELAY   (HZ/5)
#define RESTORE_LEDS  0xFF

static ssize_t readLed(struct kobject *kobj, struct kobj_attribute *attr,
                      char *buf) {
    return sprintf(buf, "%d\n", blinkMode);
}

static ssize_t writeLed(struct kobject *kobj, struct kobj_attribute *attr,
                       const char *buf, size_t count) {
    long result;
    kstrtol(buf, 10, &result);
    blinkMode = result;
    return count;
}

struct kobj_attribute attrib = __ATTR(control, 0660, readLed, writeLed);

static int sysCreate(void)
{
    int error = 0;
    ioKobject = kobject_create_and_add("kbled",
                                       kernel_kobj);
    if(!ioKobject)
        return -ENOMEM;

    error = sysfs_create_file(ioKobject, &attrib.attr);
    if (error) {
        pr_debug("failed to create the control file in /sys/kernel/kbled\n");
    }

    return error;
}

static void my_timer_func(struct timer_list *ptr)
{
    int *pstatus = &kbledStatus;
    if (*pstatus == blinkMode)
        *pstatus = RESTORE_LEDS;
    else
        *pstatus = blinkMode;
    (my_driver->ops->ioctl) (vc_cons[fg_console].d->port.tty, KDSETLED,
                             *pstatus);
    my_timer.expires = jiffies + BLINK_DELAY;
    add_timer(&my_timer);
}

static int __init kbleds_init(void)
{
    int i;
    printk(KERN_INFO "kbleds: loading\n");
    printk(KERN_INFO "kbleds: fgconsole is %x\n", fg_console);
    for (i = 0; i < MAX_NR_CONSOLES; i++) {
        if (!vc_cons[i].d)
            break;
        printk(KERN_INFO "poet_atkm: console[%i/%i] #%i, tty %lx\n", i,
                MAX_NR_CONSOLES, vc_cons[i].d->vc_num,
                (unsigned long)vc_cons[i].d->port.tty);
    }
    printk(KERN_INFO "kbleds: finished scanning consoles\n");
    my_driver = vc_cons[fg_console].d->port.tty->driver;
    printk(KERN_INFO "kbleds: tty driver major %x\n", my_driver->major);

    timer_setup(&my_timer, my_timer_func, 0);
    my_timer.expires = jiffies + BLINK_DELAY;
    add_timer(&my_timer);
    int sysErr = sysCreate();
    if (sysErr != 0) {
        return sysErr;
    }
    return 0;
}

static void __exit kbleds_cleanup(void)
{
    printk(KERN_INFO "kbleds: unloading timer\n");
    del_timer(&my_timer);
    (my_driver->ops->ioctl) (vc_cons[fg_console].d->port.tty, KDSETLED,
                             RESTORE_LEDS);
    printk(KERN_INFO "kbleds: unloading kobject\n");
    kobject_put(ioKobject);
    printk(KERN_INFO "kbleds: unloaded\n");
}
module_init(kbleds_init);
module_exit(kbleds_cleanup);
