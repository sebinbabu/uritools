#include <stdlib.h>
#include <stdio.h>
#include "uritools.h"

int main(int argc, char **argv)
{
	int p;
	uri u;
	char buf[20], *path;
	char *uri_string = argv[1];

	if (uri_check(uri_string) == 1) {
		fprintf(stderr, "Could not parse uri!\n");
		return 1;
	} else {
		if(uri_parse(&u, uri_string) == -1)
			return 1;
	}

	fprintf(stdout, "uri Values:\n");
	fprintf(stdout, "\tprotocol:\t%s\n", u.scheme);
	fprintf(stdout, "\thost:\t\t%s\n", u.host);
	fprintf(stdout, "\tpassword:\t%s\n", u.username);
	fprintf(stdout, "\tusername:\t%s\n", u.password);
	fprintf(stdout, "\tport:\t\t%s\n", u.port);
	fprintf(stdout, "\tpath:\t\t%s\n", u.path);
	fprintf(stdout, "\tquery:\t\t%s\n", u.query);
	fprintf(stdout, "\tfragment:\t%s\n", u.fragment);

	path = u.path;

	fprintf(stdout, "Split paths:\n");
	while(uri_path_split(buf, &path) > 0)
		fprintf(stdout, "\t%s\n", buf);
	fprintf(stdout, "Actual URI:\n\t%s\n", uri_reconstruct(&u));
	
	return 0;
}
