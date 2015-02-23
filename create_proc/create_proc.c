#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>

static int __init create_proc(void){
	return 0;
}

static void __exit create_proc_exit(void){

}

module_init(create_proc);
module_exit(create_proc_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("hzy.oop@gmail.com");
MODULE_DESCRIPTION("a test module for proc");
