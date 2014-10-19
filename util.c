#include "util.h"
char* read_file(char *path){
    FILE *fp;
    char *content;
    long lSize;

    fp = fopen ( path , "rb" );

    fseek( fp , 0L , SEEK_END);
    lSize = ftell( fp );
    rewind( fp );

    /* allocate memory for entire content */
    content = calloc( 1, lSize+1 );

    /* copy the file into the buffer */
    if( 1!=fread( content , lSize, 1 , fp) )
      fclose(fp),free(content),fputs("entire read fails",stderr),exit(1);

    /* do your work here, buffer is a string contains the whole text */

    fclose(fp);
    return content;
}
