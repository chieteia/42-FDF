	long cpu1_time, cpu2_time;
    double sec1, sec2;

	cpu1_time = clock();
	sec1 = (double)cpu1_time / CLOCKS_PER_SEC;
	cpu2_time = clock();
	sec2 = (double)cpu2_time / CLOCKS_PER_SEC;
	printf("time: %f\n",sec2 - sec1);