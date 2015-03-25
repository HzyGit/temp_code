#include <linux/module.h>
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/timer.h>

static struct timer_list timer;

void fun(unsigned long data){
	printk("hello\n");
	mod_timer(&timer,jiffies+HZ);
}

static int __init timer_init(void){
	init_timer(&timer);
	timer.expires=jiffies+HZ;
	timer.function=fun;
	timer.data=0;
	add_timer(&timer);
	return 0;
}

static void __exit timer_exit(void){
	del_timer_sync(&timer);
}

module_init(timer_init);
module_exit(timer_exit);
MODULE_LICENSE("GPL");
MODULE_AUTHOR("hzy hzy.oop@gmail.com");
MODULE_DESCRIPTION("a test module for timer");
