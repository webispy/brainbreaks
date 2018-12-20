#include <stdio.h>
#include <glib.h>

#include "strings.h"

int main(int argc, char *argv[])
{
	g_test_init(&argc, &argv, NULL);

	return g_test_run();
}