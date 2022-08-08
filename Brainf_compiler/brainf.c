#include <stdio.h>

void interpreter(FILE *source){
    char instruction,data[100]={0};
    int ip = 0, index=0;
    while((instruction = fgetc(source)) !=EOF){
        switch (instruction)
        {
        case '+':
            data[ip]++;
            break;
        case '-':
            data[ip]--;
            break;
        case '>':  \
            ip++;
            break;
        case '<':
            ip--;
            break;
        case '.':
            printf("%c", data[ip]);
            break;
        case ',':
            scanf("%c", &data[ip]);
            break;
        case '[':
            if(data[ip] == 0){

            }
            break;
        case ']':
            if(data[ip] != 0){

            }
            break;
        default:

            break;
        }
    }
}



int main()
{
    FILE *source = fopen("test.bf", "r");
    if (source == NULL)
    {
        printf("Error opening file\n");
        return 1;
    }
    interpreter(source);
    return 0;
}
