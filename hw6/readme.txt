
1. Issues that I ran into
	a) (Solved) At first I forgot to assign value to arguments passed in to thread functions. 
	I use gdb to figure that *((int*)arg) is constant for every thread. 
	(Before using gdb, I change the -O2 option to -Og in Makefile, and of course, I change it back later)
	
	b) A problem with srt, the executable file, is that it can only allocate more than or equal 94 threads with using the command 
		"$time ./srt 94 > /dev/null".
	It throws an error I wrote in main.c
		"Error in creating threads"

	However, the program runs successfully under gdb.

		[classzfu@lnxsrv09 ~/35l/hw6/srt]$ gdb ./srt
		GNU gdb (GDB) Red Hat Enterprise Linux 7.6.1-94.el7
		Copyright (C) 2013 Free Software Foundation, Inc.
		License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>
		This is free software: you are free to change and redistribute it.
		There is NO WARRANTY, to the extent permitted by law.  Type "show copying"
		and "show warranty" for details.
		This GDB was configured as "x86_64-redhat-linux-gnu".
		For bug reporting instructions, please see:
		<http://www.gnu.org/software/gdb/bugs/>...
		Reading symbols from /w/home.14/class/classzfu/35l/hw6/srt/srt...done.
		(gdb) r 94 > /dev/null
		Starting program: /w/home.14/class/classzfu/35l/hw6/srt/./srt 94 > /dev/null
		[Thread debugging using libthread_db enabled]
		Using host libthread_db library "/lib64/libthread_db.so.1".
		[New Thread 0x7ffff74fd700 (LWP 43381)]
		[New Thread 0x7ffff6cfc700 (LWP 43382)]
		[New Thread 0x7ffff64fb700 (LWP 43383)]
		[New Thread 0x7ffff5cfa700 (LWP 43384)]
		[New Thread 0x7ffff54f9700 (LWP 43385)]
		[New Thread 0x7ffff4cf8700 (LWP 43386)]
		[New Thread 0x7ffff44f7700 (LWP 43387)]
		[New Thread 0x7ffff3cf6700 (LWP 43388)]
		[New Thread 0x7ffff34f5700 (LWP 43389)]
		[New Thread 0x7ffff2cf4700 (LWP 43390)]
		[New Thread 0x7ffff24f3700 (LWP 43391)]
		[New Thread 0x7ffff1cf2700 (LWP 43392)]
		[New Thread 0x7ffff14f1700 (LWP 43393)]
		[New Thread 0x7ffff0cf0700 (LWP 43394)]
		[New Thread 0x7ffff04ef700 (LWP 43395)]
		[New Thread 0x7fffefcee700 (LWP 43396)]
		[New Thread 0x7fffef4ed700 (LWP 43397)]
		[New Thread 0x7fffeecec700 (LWP 43398)]
		[New Thread 0x7fffee4eb700 (LWP 43399)]
		[New Thread 0x7fffedcea700 (LWP 43400)]
		[New Thread 0x7fffed4e9700 (LWP 43401)]
		[New Thread 0x7fffecce8700 (LWP 43402)]
		[New Thread 0x7fffdffff700 (LWP 43403)]
		[New Thread 0x7fffdf7fe700 (LWP 43404)]
		[New Thread 0x7fffdeffd700 (LWP 43405)]
		[New Thread 0x7fffde7fc700 (LWP 43406)]
		[New Thread 0x7fffddffb700 (LWP 43407)]
		[New Thread 0x7fffdd7fa700 (LWP 43408)]
		[New Thread 0x7fffdcff9700 (LWP 43409)]
		[New Thread 0x7fffd3fff700 (LWP 43410)]
		[New Thread 0x7fffd37fe700 (LWP 43411)]
		[New Thread 0x7fffd2ffd700 (LWP 43412)]
		[New Thread 0x7fffd27fc700 (LWP 43413)]
		[New Thread 0x7fffd1ffb700 (LWP 43414)]
		[New Thread 0x7fffd17fa700 (LWP 43415)]
		[New Thread 0x7fffd0ff9700 (LWP 43416)]
		[New Thread 0x7fff5bfff700 (LWP 43417)]
		[New Thread 0x7fff5b7fe700 (LWP 43418)]
		[New Thread 0x7fff5affd700 (LWP 43419)]
		[New Thread 0x7fff5a7fc700 (LWP 43420)]
		[New Thread 0x7fff59ffb700 (LWP 43421)]
		[New Thread 0x7fff597fa700 (LWP 43422)]
		[New Thread 0x7fff58ff9700 (LWP 43423)]
		[New Thread 0x7fff37fff700 (LWP 43424)]
		[New Thread 0x7fff377fe700 (LWP 43425)]
		[New Thread 0x7fff36ffd700 (LWP 43426)]
		[New Thread 0x7fff367fc700 (LWP 43427)]
		[New Thread 0x7fff35ffb700 (LWP 43428)]
		[New Thread 0x7fff357fa700 (LWP 43429)]
		[New Thread 0x7fff34ff9700 (LWP 43430)]
		[New Thread 0x7fff17fff700 (LWP 43431)]
		[New Thread 0x7fff177fe700 (LWP 43432)]
		[New Thread 0x7fff16ffd700 (LWP 43433)]
		[New Thread 0x7fff167fc700 (LWP 43434)]
		[New Thread 0x7fff15ffb700 (LWP 43435)]
		[New Thread 0x7fff157fa700 (LWP 43436)]
		[New Thread 0x7fff14ff9700 (LWP 43437)]
		[New Thread 0x7ffef7fff700 (LWP 43438)]
		[New Thread 0x7ffef77fe700 (LWP 43439)]
		[Thread 0x7fff5b7fe700 (LWP 43418) exited]
		[New Thread 0x7ffef6ffd700 (LWP 43440)]
		[New Thread 0x7ffef67fc700 (LWP 43441)]
		[New Thread 0x7ffef5ffb700 (LWP 43442)]
		[New Thread 0x7ffef57fa700 (LWP 43443)]
		[Thread 0x7fffecce8700 (LWP 43402) exited]
		[New Thread 0x7ffef4ff9700 (LWP 43444)]
		[New Thread 0x7ffee7fff700 (LWP 43445)]
		[Thread 0x7fff5affd700 (LWP 43419) exited]
		[New Thread 0x7ffee77fe700 (LWP 43446)]
		[Thread 0x7fffeecec700 (LWP 43398) exited]
		[Thread 0x7fffd2ffd700 (LWP 43412) exited]
		[New Thread 0x7ffee6ffd700 (LWP 43447)]
		[Thread 0x7fffd27fc700 (LWP 43413) exited]
		[New Thread 0x7ffee67fc700 (LWP 43448)]
		[New Thread 0x7ffee5ffb700 (LWP 43449)]
		[Thread 0x7fffefcee700 (LWP 43396) exited]
		[Thread 0x7fffd37fe700 (LWP 43411) exited]
		[Thread 0x7fffdeffd700 (LWP 43405) exited]
		[Thread 0x7ffff1cf2700 (LWP 43392) exited]
		[New Thread 0x7ffee57fa700 (LWP 43450)]
		[Thread 0x7fffedcea700 (LWP 43400) exited]
		[New Thread 0x7ffee4ff9700 (LWP 43451)]
		[Thread 0x7fffde7fc700 (LWP 43406) exited]
		[New Thread 0x7ffedbfff700 (LWP 43452)]
		[Thread 0x7fffdcff9700 (LWP 43409) exited]
		[Thread 0x7ffff44f7700 (LWP 43387) exited]
		[Thread 0x7fffef4ed700 (LWP 43397) exited]
		[Thread 0x7fffd17fa700 (LWP 43415) exited]
		[Thread 0x7ffff0cf0700 (LWP 43394) exited]
		[Thread 0x7fff5a7fc700 (LWP 43420) exited]
		[Thread 0x7fffd3fff700 (LWP 43410) exited]
		[Thread 0x7fff5bfff700 (LWP 43417) exited]
		[Thread 0x7ffff04ef700 (LWP 43395) exited]
		[New Thread 0x7ffedb7fe700 (LWP 43453)]
		[Thread 0x7fffdf7fe700 (LWP 43404) exited]
		[New Thread 0x7ffedaffd700 (LWP 43454)]
		[Thread 0x7ffff2cf4700 (LWP 43390) exited]
		[Thread 0x7fff59ffb700 (LWP 43421) exited]
		[Thread 0x7ffff74fd700 (LWP 43381) exited]
		[Thread 0x7fff377fe700 (LWP 43425) exited]
		[Thread 0x7fffee4eb700 (LWP 43399) exited]
		[New Thread 0x7ffeda7fc700 (LWP 43455)]
		[Thread 0x7fffed4e9700 (LWP 43401) exited]
		[Thread 0x7ffff6cfc700 (LWP 43382) exited]
		[New Thread 0x7ffed9ffb700 (LWP 43456)]
		[Thread 0x7fffd0ff9700 (LWP 43416) exited]
		[Thread 0x7fff37fff700 (LWP 43424) exited]
		[Thread 0x7fffddffb700 (LWP 43407) exited]
		[Thread 0x7ffff64fb700 (LWP 43383) exited]
		[New Thread 0x7ffed97fa700 (LWP 43457)]
		[New Thread 0x7ffed8ff9700 (LWP 43458)]
		[Thread 0x7fffd1ffb700 (LWP 43414) exited]
		[Thread 0x7fff36ffd700 (LWP 43426) exited]
		[Thread 0x7ffff14f1700 (LWP 43393) exited]
		[Thread 0x7fff58ff9700 (LWP 43423) exited]
		[Thread 0x7fff597fa700 (LWP 43422) exited]
		[Thread 0x7ffff5cfa700 (LWP 43384) exited]
		[New Thread 0x7ffed87f8700 (LWP 43459)]
		[New Thread 0x7ffed7ff7700 (LWP 43460)]
		[Thread 0x7fff357fa700 (LWP 43429) exited]
		[Thread 0x7ffff4cf8700 (LWP 43386) exited]
		[Thread 0x7ffff3cf6700 (LWP 43388) exited]
		[New Thread 0x7ffed77f6700 (LWP 43462)]
		[Thread 0x7fffdffff700 (LWP 43403) exited]
		[Thread 0x7ffff24f3700 (LWP 43391) exited]
		[New Thread 0x7ffed6ff5700 (LWP 43463)]
		[Thread 0x7fff367fc700 (LWP 43427) exited]
		[Thread 0x7fffdd7fa700 (LWP 43408) exited]
		[New Thread 0x7ffed67f4700 (LWP 43464)]
		[New Thread 0x7ffed5ff3700 (LWP 43465)]
		[Thread 0x7fff35ffb700 (LWP 43428) exited]
		[New Thread 0x7ffed57f2700 (LWP 43466)]
		[New Thread 0x7ffed4ff1700 (LWP 43467)]
		[New Thread 0x7ffed47f0700 (LWP 43468)]
		[New Thread 0x7ffed3fef700 (LWP 43469)]
		[Thread 0x7ffff54f9700 (LWP 43385) exited]
		[New Thread 0x7ffed37ee700 (LWP 43470)]
		[Thread 0x7fff34ff9700 (LWP 43430) exited]
		[New Thread 0x7ffed2fed700 (LWP 43471)]
		[New Thread 0x7ffed27ec700 (LWP 43472)]
		[Thread 0x7ffff34f5700 (LWP 43389) exited]
		[New Thread 0x7ffed1feb700 (LWP 43473)]
		[New Thread 0x7ffed17ea700 (LWP 43474)]
		[New Thread 0x7ffed0fe9700 (LWP 43475)]
		[Thread 0x7fff17fff700 (LWP 43431) exited]
		[Thread 0x7fff16ffd700 (LWP 43433) exited]
		[Thread 0x7fff177fe700 (LWP 43432) exited]
		[Thread 0x7fff167fc700 (LWP 43434) exited]
		[Thread 0x7fff15ffb700 (LWP 43435) exited]
		[Thread 0x7fff14ff9700 (LWP 43437) exited]
		[Thread 0x7fff157fa700 (LWP 43436) exited]
		[Thread 0x7ffef7fff700 (LWP 43438) exited]
		[Thread 0x7ffef77fe700 (LWP 43439) exited]
		[Thread 0x7ffed47f0700 (LWP 43468) exited]
		[Thread 0x7ffed0fe9700 (LWP 43475) exited]
		[Thread 0x7ffed5ff3700 (LWP 43465) exited]
		[Thread 0x7ffed4ff1700 (LWP 43467) exited]
		[Thread 0x7ffef5ffb700 (LWP 43442) exited]
		[Thread 0x7ffed2fed700 (LWP 43471) exited]
		[Thread 0x7ffed57f2700 (LWP 43466) exited]
		[Thread 0x7ffed17ea700 (LWP 43474) exited]
		[Thread 0x7ffed27ec700 (LWP 43472) exited]
		[Thread 0x7ffed3fef700 (LWP 43469) exited]
		[Thread 0x7ffef6ffd700 (LWP 43440) exited]
		[Thread 0x7ffef57fa700 (LWP 43443) exited]
		[Thread 0x7ffed67f4700 (LWP 43464) exited]
		[Thread 0x7ffed9ffb700 (LWP 43456) exited]
		[Thread 0x7ffedb7fe700 (LWP 43453) exited]
		[Thread 0x7ffed1feb700 (LWP 43473) exited]
		[Thread 0x7ffef67fc700 (LWP 43441) exited]
		[Thread 0x7ffee4ff9700 (LWP 43451) exited]
		[Thread 0x7ffed77f6700 (LWP 43462) exited]
		[Thread 0x7ffedbfff700 (LWP 43452) exited]
		[Thread 0x7ffee57fa700 (LWP 43450) exited]
		[Thread 0x7ffed37ee700 (LWP 43470) exited]
		[Thread 0x7ffedaffd700 (LWP 43454) exited]
		[Thread 0x7ffed97fa700 (LWP 43457) exited]
		[Thread 0x7ffee5ffb700 (LWP 43449) exited]
		[Thread 0x7ffeda7fc700 (LWP 43455) exited]
		[Thread 0x7ffee6ffd700 (LWP 43447) exited]
		[Thread 0x7ffee67fc700 (LWP 43448) exited]
		[Thread 0x7ffed8ff9700 (LWP 43458) exited]
		[Thread 0x7ffed6ff5700 (LWP 43463) exited]
		[Thread 0x7ffef4ff9700 (LWP 43444) exited]
		[Thread 0x7ffed87f8700 (LWP 43459) exited]
		[Thread 0x7ffed7ff7700 (LWP 43460) exited]
		[Thread 0x7ffee7fff700 (LWP 43445) exited]
		[Thread 0x7ffee77fe700 (LWP 43446) exited]
		[Inferior 1 (process 43377) exited normally]

	What is the weirdest, when I try the program 12hrs later, the maximum threads that it can allocate is 97, instead of 94. 
		[classzfu@lnxsrv09 ~/35l/hw6/srt]$ time ./srt 95 > /dev/null

		real    0m2.832s
		user    1m20.112s
		sys     0m0.032s
		[classzfu@lnxsrv09 ~/35l/hw6/srt]$ time ./srt 96 > /dev/null

		real    0m2.741s
		user    1m20.161s
		sys     0m0.012s
		[classzfu@lnxsrv09 ~/35l/hw6/srt]$ time ./srt 97 > /dev/null

		real    0m2.842s
		user    1m19.778s
		sys     0m0.008s
		[classzfu@lnxsrv09 ~/35l/hw6/srt]$ time ./srt 98 > /dev/null
		Error in creating threads

		real    0m0.005s
		user    0m0.043s
		sys     0m0.025s

	I browse on the Internet and find out that the error is caused by the limited resource the kernal or system allocating to pthreads, which is Error 11.

-------------------------------------------------------------------------------

2. Conclusions about how well your implementation of SRT improves its performance

	[classzfu@lnxsrv09 ~/35l/hw6/srt]$ time ./srt 1 > /dev/null

	real    0m41.148s
	user    0m41.146s
	sys     0m0.002s
	[classzfu@lnxsrv09 ~/35l/hw6/srt]$ time ./srt 2 > /dev/null

	real    0m20.631s
	user    0m41.043s
	sys     0m0.001s
	[classzfu@lnxsrv09 ~/35l/hw6/srt]$ time ./srt 4 > /dev/null

	real    0m10.896s
	user    0m43.026s
	sys     0m0.000s
	[classzfu@lnxsrv09 ~/35l/hw6/srt]$ time ./srt 8 > /dev/null

	real    0m5.740s
	user    0m44.552s
	sys     0m0.002s
	[classzfu@lnxsrv09 ~/35l/hw6/srt]$ time ./srt 16 > /dev/null

	real    0m2.942s
	user    0m44.548s
	sys     0m0.003s
	[classzfu@lnxsrv09 ~/35l/hw6/srt]$ time ./srt 32 > /dev/null

	real    0m2.796s
	user    1m19.569s
	sys     0m0.008s
	[classzfu@lnxsrv09 ~/35l/hw6/srt]$ time ./srt 64 > /dev/null

	real    0m3.018s
	user    1m19.949s
	sys     0m0.005s

Since the multithreading function is used, the user time = real time * number of threads + overheads. 
The real time period for user or wait is reduced by a factor of number of threads approximately. 
The multithreading generally significantly improve the performance cause it splits a process into multiple threads to compute on a CPU with multiple cores. 
However, we can figure out that when number of threads is too large, much larger than the actual cores of the CPU leading to time sharing of threads, 
or each thread just does few simple tasks, the time to create pthreads and to join pthreads prolong the process by adding time in the overhead term in the equation.