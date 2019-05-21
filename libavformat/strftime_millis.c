#include "strftime_millis.h"
#include "libavutil/time_internal.h"

size_t strftime_millis(char* ptr, size_t maxsize,const char* format, const struct timeval* tv)
{
    struct tm *tm, tmpbuf;
    size_t result;
    char* temp_name = malloc(maxsize);
    time_t t = tv->tv_sec;
    if((tm = localtime_r(&(t), &tmpbuf)) == NULL) {
        printf("localtime is error\n");
        return 0;
    }

    strftime(temp_name, maxsize, format, tm);
    result = snprintf(ptr, maxsize, temp_name, tv->tv_usec/1000);
    free(temp_name);
    return result;    
}
