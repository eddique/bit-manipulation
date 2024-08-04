#include "common.h"
#include "pin.h"
#include "posts.h"
#include <stdlib.h>

void http_run()
{
	int post = 20;
	create_post();
	list_posts();
	get_post(post);
	update_post(post);
	delete_post(post);
}

int main(int argc, char *argv[])
{
	printf("running http requests...\n");
	http_run();

	printf("running pin: PD3\n\n");
	pin_run_pd3();

	if (argc > 1)
	{
		char *pin_arg = argv[argc - 1];
		int pin = atoi(pin_arg);
		if (pin >= 0 && pin < 8)
		{
			printf("running pin: %s\n\n", pin_arg);
			pin_run(pin);
		}
		else
			printf("[error] invalid pin provided: %s\n", pin_arg);
	}
	int hex_num = 0x00FF0000;
	endianness(hex_num);
	return 0;
}