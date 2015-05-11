#include <linux/module.h>
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/sched.h>
#include <asm-generic/current.h>

const char *task_stat[]={
	"TASK_RUNNING",
	"TASK_INTERRUPTIBLE",
	"TASK_UNINTERRUPTIBLE"
};

static void display_current(void){
	printk("current: %d %d %s\n",current->pid,current->tgid,current->comm);
};

static void display_thread(const struct task_struct *p){
	const char *info="unknown";
	if(p->state>=0&&p->state<=ARRAY_SIZE(task_stat)){
		info=task_stat[p->state];
	}
	pr_info("pid:%d tgid:%d name:%s stats:%s\n",
			p->pid,p->tgid,p->comm,info);
}

static void display_all_thread(void){
	struct task_struct *p;
	for_each_process(p){
		display_thread(p);
	};
}

static int thread_init(void){
	display_current();
	pr_info("display all thread\n");
	display_all_thread();
	pr_info("load thread ok\n");
	return 0;
}

static void thread_exit(void){
	pr_info("unload thread ok\n");
}

module_init(thread_init);
module_exit(thread_exit);
MODULE_LICENSE("GPL");
MODULE_AUTHOR("hzy.oop@gmail.com");
MODULE_DESCRIPTION("a test module for task_struct");
