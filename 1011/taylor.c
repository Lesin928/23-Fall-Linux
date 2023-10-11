#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <math.h>

#define _USE_MATH_DEFINES
#define N 4

void sinx_taylor(int num_elements, int terms, double *x, double *result);

int main() {
	    double x[N] = {0, M_PI / 6.0, M_PI / 3.0, 0.134};
	        double res[N];

	      	sinx_taylor(N, 3, x, res);
		for (int i = 0; i < N; i++) {
			printf("sin(%.2f) by Taylor series = %f\n", x[i], res[i]);
			printf("sin(%.2f) = %f\n", x[i], sin(x[i]));
		}	
		return 0;
}


void sinx_taylor(int num_elements, int terms, double *x, double *result) {
	int pipe_fd[N][2];
	for (int i = 0; i < N; i++) {
		if (pipe(pipe_fd[i]) == -1) {
			perror("Pipe creation failed");
			exit(EXIT_FAILURE);
		}
	}
	
	for (int i = 0; i < N; i++) {
		pid_t child_pid = fork();
		
		if (child_pid == -1) {
			perror("Fork failed");
			exit(EXIT_FAILURE);
		}

		if (child_pid == 0) {  
			close(pipe_fd[i][0]); 
			double value = x[i];
			double number = x[i] * x[i] * x[i];
			double denom = 6.0;
			int sign = -1;
			
			for (int j = 0; j <= terms; j++) {
				value += (double)sign * number / denom;
				number *= x[i] * x[i];
				denom *= (2.0 * (double)j + 2.0) * (2.0 * (double)j + 3.0);
				sign *= -1;
			}
			
			write(pipe_fd[i][1], &value, sizeof(double)); 
			close(pipe_fd[i][1]);
			exit(0);
		}
	}
	
			        for (int i = 0; i < N; i++) {
					close(pipe_fd[i][1]); 
					read(pipe_fd[i][0], &result[i], sizeof(double));
					close(pipe_fd[i][0]);
				}
				
    				int status;
				for (int i = 0; i < N; i++) {
					wait(&status);
				}
}

