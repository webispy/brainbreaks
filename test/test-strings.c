#include <stdio.h>
#include <glib.h>

#include "strings.h"

static void tc_reverseString()
{
    char data[99];
    char *want1 = "olleh";
    char *want2 = "amanaP :lanac a ,nalp a ,nam A";

    g_assert(reverseString(NULL) == NULL);

    memcpy(data, "hello\0", 6);
    g_assert_cmpstr(reverseString(data), ==, want1);

    memcpy(data, "A man, a plan, a canal: Panama\0", 31);
    g_assert_cmpstr(reverseString(data), ==, want2);
}

int main(int argc, char *argv[])
{
	g_test_init(&argc, &argv, NULL);

	g_test_add_func("/strings/reverseString", tc_reverseString);

	return g_test_run();
}