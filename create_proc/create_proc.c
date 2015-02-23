#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>

#include <linux/fs.h>
#include <linux/proc_fs.h>
#include <linux/seq_file.h>
#include <linux/jiffies.h>

#include "create_proc.h"
static struct proc_dir_entry *jif_file;

static int jif_show(struct seq_file *m,void *v){
	seq_printf(m,"%llu\n",(unsigned long long)get_jiffies_64());
	return 0;
}

static int jif_open(struct inode *inode,struct file *file){
	return single_open(file,jif_show,NULL);
}

static const struct file_operations jif_fops={
	.owner=THIS_MODULE,
	.open=jif_open,
	.read=seq_read,
	.llseek=seq_lseek,
	.release=single_release,
};

static int __init create_proc(void){
	jif_file=proc_create(PROC_NAME,0,NULL,&jif_fops);
	if(!jif_file)
		return -ENOMEM;
	return 0;
}

static void __exit create_proc_exit(void){
	remove_proc_entry(PROC_NAME,NULL);
}

module_init(create_proc);
module_exit(create_proc_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("hzy.oop@gmail.com");
MODULE_DESCRIPTION("a test module for proc");
