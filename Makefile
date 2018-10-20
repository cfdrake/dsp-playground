CC=gcc

redux: redux.c
	$(CC) redux.c -o redux

delay: delay.c
	$(CC) delay.c -o delay

saw: saw.c
	$(CC) saw.c -o saw
