#include <fcntl.h>
#include <json-c/json.h>
#include <stdio.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>
char gk2[] = "{\"data\":{\"definitions\":[{\"text\":\"To have or take on the appearance, form, or "
             "sound of; "
             "imitate.\",\"partOfSpeech\":\"verb-transitive\",\"sequence\":0},{\"text\":\"To make "
             "in imitation of or as a substitute for. See Synonyms at "
             "imitate.\",\"partOfSpeech\":\"verb-transitive\",\"sequence\":1},{\"text\":\"To make "
             "a pretense of; feign:  simulate interest. "
             "\",\"partOfSpeech\":\"verb-transitive\",\"sequence\":2},{\"text\":\"To create a "
             "representation or model of (a physical system or particular situation, for "
             "example).\",\"partOfSpeech\":\"verb-transitive\",\"sequence\":3}]}}";
// char *rem(char *str, char *newstr, char c) {
//     char *f = strchr(str, c) + 1;
//     f = (*f) == ' ' ? f+1 : f;
//     char *l = strrchr(str, c) - 1;
//     puts(l);
//     l = (*l) == ' ' ? l-1 : l;
//     strncpy(newstr, f, strlen(gk) - strlen(l) + 1);
//     return newstr;
// }


char *rem2(char *str, char *newstr, char c1, char c2) {
    char *f = strchr(str, c1) + 1;
    char *l = strrchr(str, c2) - 1;
    strncpy(newstr, f, strlen(f) - strlen(l) + 1);
    newstr[strlen(f) - strlen(l) + 1] = '\0';
    return newstr;
}

// char *remp(char *str, char *newstr) {
//     char *f = strchr(str, '"') + 1;
//     char *f1 = strchr(f, '"') + 2;
//     char *l = strrchr(str, '"') - 1;
//     char *l1 = strrchr(f, '"') - 2;
//     rem(str, newstr);
// }
char name[] = "g{anesnabc}h";
int main(void) {
    char gk[1048];
    int fd, n;
    fd = open("body.json", O_RDONLY);
    if ((n = read(fd, gk, 1048)) < 0) {
        puts("something went wrong");
        exit(1);
    }
    char *json = mmap(gk, n, PROT_READ, MAP_PRIVATE, fd, 0);
    close(fd);
    struct json_object *obj;
    obj = json_tokener_parse(json);
    // struct json_object *json;
    // char test2[1024] = "";
    // // strncat(test2, f, strlen(gk) - strlen(l));
    char name2[2048] = "";
    // // rem(gk, test2, '{');
    // char *f = strchr(gk, '{') + 1;
    // char *l = strrchr(gk, '}') - 1;
    // strncpy(name2, f, strlen(f) - strlen(l) + 1);
    // puts(gk);
    // putchar('\n');
    json_object_object_foreach(obj, key, val) {
        // printf("key = %s value = %s\n", key, json_object_get_string(val));
        json_object_object_foreach(val, key, val2) {
            // printf("key = %s value = %s\n", key, json_object_get_string(val2));
            struct json_object *arr;
            int i, len = json_object_array_length(val2);
            for (i = 0; i < len; i++) {
                arr = json_object_array_get_idx(val2, i); // check out this
                printf("%s\n", json_object_get_string(arr));
            }
            // json_object_object_foreach(val, key2, val22) {
            //     printf("key = %s value = %s\n", key, json_object_get_string(val22));
            // }
            // json_object_object_foreach(val2, key, val3) {
            //     printf("key = %s value = %s\n", key, json_object_get_string(val3));
            // }
            // size_t si = json_object_array_length(val2);
            // printf("%lu\n", si);
            struct json_object *gj = json_object_array_get_idx(val2, 4);
            // json_object_array
        }
    }
    rem2(gk, name2, '{', '}');
    // puts(name2);
    // putchar('\n');
    rem2(name2, name2, '{', '}');
    // puts(name2);
    // putchar('\n');
    rem2(name2, name2, '[', ']');
    // puts(name2);
    // puts(test2);
    // putchar('\n');
    // rem(gk, test2, '{');
    // puts(test2);
    // char buf[1048];
    // int i, fd, n;
    // fd = open("body.json", O_RDONLY);
    // if ((n = read(fd, buf, 1048)) < 0) {
    //     puts("something went wrong");
    //     exit(1);
    // }
    // json = json_object_new_object();
    // json_object_object_add(json, )
    return 0;
}