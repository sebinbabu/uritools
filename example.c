#include <stdlib.h>
#include <stdio.h>
#include "uritools.h"

int main(int argc, char **argv)
{
	int p;
	uri u;
	char buf[20], *path;
	char *uri_string = argv[1];

	if (uri_parse(&u, uri_string) == -1) {
		fprintf(stderr, "Could not parse uri!\n");
		return 1;
	}

	fprintf(stdout, "uri Values:\n");
	fprintf(stdout, "\tprotocol:\t%s\n", u.scheme);
	fprintf(stdout, "\thost:\t\t%s\n", u.host);
	fprintf(stdout, "\tport:\t\t%d\n", u.port);
	fprintf(stdout, "\tpath:\t\t%s\n", u.path);
	fprintf(stdout, "\tquery:\t\t%s\n", u.query);
	fprintf(stdout, "\tfragment:\t%s\n", u.fragment);

	path = u.path;

	fprintf(stdout, "Split paths:\n");
	while(uri_path_split(buf, &path) > 0)
		printf("\t%s\n", buf);
	return 0;
}
