#include <linux/linkage.h>
#include <linux/kernel.h>
#include <linux/uaccess.h>
#include <linux/time.h>

#define MY_MAX_BUF_LEN 100

asmlinkage long sys_hello_utcs(const char __user *buf, int len){
	char my_buf[MY_MAX_BUF_LEN + 1];
	if(len < 0){
		printk(KERN_DEBUG "Invalid buffer length\n");
		return  -ENOMEM;
	} else if (len > MY_MAX_BUF_LEN){
		len = MY_MAX_BUF_LEN;
	}
	if(copy_from_user(my_buf, buf, len)){
		return  -EFAULT;
	}
	my_buf[len]='\0';
	
	printk(KERN_INFO "Hello %s\n", my_buf);
	return 0;
}

asmlinkage long sys_get_system_time(struct timeval __user *tv){
	struct timeval dummy;
	do_gettimeofday(&dummy);
	
	if(copy_to_user(tv, &dummy, sizeof(struct timeval))){
		return -EFAULT;
	}

	return 0;
}
