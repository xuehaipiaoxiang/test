#input : the first address
#output: count of chars,which stored in %eax

.type count_chars,@function
.globl count_chars
.equ STUFIX,8

count_chars:
	push %ebp
	movl %esp,%ebp
	mov $0,%ecx ;counter
	movl STUFIX(%ebp),%edx;the first address
count_loop_begin:
	movb (%edx),%al
	cmpb $0,%al
	je count_loop_en
	incl %ecx
	incl %edx
count_loop_end:
	movl %ecx,%eax
	popl %ebp ;restore base pointer
	ret

