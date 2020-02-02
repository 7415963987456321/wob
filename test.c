#define WOB_TEST
#include "wob.c"

int
main(int argc, char **argv)
{
	unsigned long percentage;
	struct wob_colors colors = {0, 0, 0};
	char *input;
	bool result;

	printf("running 1\n");
	input = "25 #FF000000 #FFFFFFFF #FFFFFFFF\n";
	result = wob_parse_input(input, &percentage, &colors);
	if (!result || percentage != 25 || colors.background != 0xFF000000 || colors.border != 0xFFFFFFFF || colors.bar != 0xFFFFFFFF) {
		return EXIT_FAILURE;
	}

	printf("running 2\n");
	input = "25 #FF000000\n";
	result = wob_parse_input(input, &percentage, &colors);
	if (result) {
		return EXIT_FAILURE;
	}

	printf("running 3\n");
	input = "25\n";
	result = wob_parse_input(input, &percentage, &colors);
	if (!result || percentage != 25) {
		return EXIT_FAILURE;
	}

	printf("running 4\n");
	input = "25 #FF000000 #FFFFFFFF #FFFFFFFF \n";
	result = wob_parse_input(input, &percentage, &colors);
	if (result) {
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}
