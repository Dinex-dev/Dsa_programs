#include <stdio.h>
int fun(int pos, char array[],char c)
{
        switch (c)
        {
        case '>':
            pos++;
            break;
        case '<':
            pos--;
            break;
        case '+':
            array[pos]++;
            break;
        case '-':
            array[pos]--;
            break;
        case '.':
            printf("%c", array[pos]);
            break;
        case ',':
            scanf("%c", &array[pos]);
            break;
        default:
            break;
        }
}

int looper(FILE *file, char array[], int pos)
{
    char c;
    while ((c = fgetc(file)) != EOF)
    {
        if(c!='['){
        fun(pos, array, c);
        }
        else if (c==']')
        {
            
        }
        
        
    }
}

int main(int argc, char const *argv[])
{
    // check program arguments
    // if (argc != 2)
    // {
    //     printf("Usage: %s <file_name>\n", argv[0]);
    //     return 1;
    // }
    // open file
    FILE *file = fopen("./brainf.f", "r"); // argv[1]
    if (file == NULL)
    {
        printf("Error opening file\n");
        return 1;
    }
    int pos = 0;
    char array[100] = {0},c;
    
    

    return 0;
}