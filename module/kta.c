/*
 * Módulo de kernel que desprotege o processo init de receber um kill -9
 * Autores:
 * 	Francisco Machado Magalhães Neto
 */

#include <linux/module.h>
#include <linux/sched.h>

MODULE_LICENSE("GPL");

int init_module() {

	struct task_struct *target_task = pid_task(find_vpid(1), PIDTYPE_PID);

	if (!target_task) {
		return -EINVAL;
	}

	target_task->signal->flags &= ~SIGNAL_UNKILLABLE;

	printk(KERN_INFO "%s: FLAGS = 0x%X\n", target_task->comm, target_task->signal->flags);

	return 0;
}
void cleanup_module() {

}
