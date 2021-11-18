#include <iostream>
#include <getopt.h>
#include <vector>
#include <algorithm>


int main (int argc, char *argv[]) {
	const char* short_options = "hvas:";

	const struct option long_options[] = {
		{"help", no_argument, NULL, 'h'},
		{"version", no_argument, NULL, 'v'},
		{"abracadabra", no_argument, NULL, 'a'},
		{"say", required_argument, NULL, 's'},
		{NULL,0,NULL,0}
	};

	int result;
	int option_index;

	std::vector<int> parsed_args;

	while ((result=getopt_long(argc,argv,short_options,long_options,&option_index)) != -1) {

		if (std::count(parsed_args.begin(), parsed_args.end(), result)) {
			continue;
		} else {
			parsed_args.push_back(result);
		}

		switch (result) {
			case 'h':
				std::cout << "Arg: Help\n";
				break;
			case 'v':
				std::cout << "Arg: Version\n";
				break;
			case 'a':
				std::cout << "Arg: Abracadabra\n";
				break;
			case 's':
				std::cout << "Arg: Say, value: " << optarg << std::endl;
				break;
			default:
				break;
		}
	}

	return 0;
}
