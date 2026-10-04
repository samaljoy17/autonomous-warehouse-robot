#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/fs.h>
#include <linux/miscdevice.h>
#include <linux/uaccess.h>

struct warehouse_sensor_data
{
    int x;
    int y;
    int front_blocked;
    int left_blocked;
    int right_blocked;
};

#define WAREHOUSE_MAGIC 'W'

#define WAREHOUSE_SET_SENSOR \
    _IOW(WAREHOUSE_MAGIC, 1, struct warehouse_sensor_data)

#define WAREHOUSE_GET_SENSOR \
    _IOR(WAREHOUSE_MAGIC, 2, struct warehouse_sensor_data)

static struct warehouse_sensor_data sensor_data;

static long warehouse_ioctl(struct file *file,
                            unsigned int command,
                            unsigned long arg)
{
    switch (command)
    {
        case WAREHOUSE_SET_SENSOR:

            if (copy_from_user(&sensor_data,
                               (void __user *)arg,
                               sizeof(sensor_data)))
            {
                return -EFAULT;
            }

            printk(KERN_INFO
                   "warehouse_sensor: sensor data updated\n");

            return 0;

        case WAREHOUSE_GET_SENSOR:

            if (copy_to_user((void __user *)arg,
                             &sensor_data,
                             sizeof(sensor_data)))
            {
                return -EFAULT;
            }

            return 0;

        default:
            return -EINVAL;
    }
}

static const struct file_operations warehouse_fops =
{
    .owner = THIS_MODULE,
    .unlocked_ioctl = warehouse_ioctl,
};

static struct miscdevice warehouse_device =
{
    .minor = MISC_DYNAMIC_MINOR,
    .name = "warehouse_sensor",
    .fops = &warehouse_fops,
    .mode = 0666
};

static int __init warehouse_driver_init(void)
{
    int result;

    sensor_data.x = 0;
    sensor_data.y = 0;
    sensor_data.front_blocked = 0;
    sensor_data.left_blocked = 0;
    sensor_data.right_blocked = 0;

    result = misc_register(&warehouse_device);

    if (result != 0)
    {
        printk(KERN_ERR
               "warehouse_sensor: registration failed\n");

        return result;
    }

    printk(KERN_INFO
           "warehouse_sensor: driver loaded\n");

    return 0;
}

static void __exit warehouse_driver_exit(void)
{
    misc_deregister(&warehouse_device);

    printk(KERN_INFO
           "warehouse_sensor: driver unloaded\n");
}

module_init(warehouse_driver_init);
module_exit(warehouse_driver_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Student");
MODULE_DESCRIPTION("Virtual Warehouse Robot Sensor Driver");
