#include <stdio.h>

/**
 * 文件操作
 *  定义一个文件指针： FILE *fp;
 *  打开文件： fopen(path, mod)  mod = [r, w, a, rb, wb, ab, r+, w+, a+, rb+, wb+ ab+], xb代表二进制文件，x代表文本文件， +代表读写 
 *  关闭文件： fclose(文件指针)
 *  读取文件内容： fgetc(), fgets(), fscanf(), fread()
 *  给文件写内容： fputc(), fputs(), fprintf(), fwrite()
 *      fread()/fwrite()主要用于二进制文件的读取写入， 不建议对文本文件采用该方式进行操作
 *  文件定位： fseek(), rewind(), ftell()
 *  文件内容结束判断： feof()
 **/


// 读取文件
void readFileText(){
    FILE *fp;
    fp = fopen("E:\\VSCodeWorkSpace\\CCode\\baseGrammar\\test1.txt", "r");
    
    char c, str[5], sca[5], sfr[5];
    
    c = fgetc(fp);                  // fgetc(*fp) 传入FLLE类型的指针， 返回读出的值 
    fgets(str, sizeof(str), fp);    // fgets(char *, count, *fp)
    fscanf(fp, "%s", sca);          // fscanf(*fp, 格式字符串，接收参数) 格式字符串：%d, %c, %s； 接收参数为指针类型

    printf("getc =%c, gets =%s, fscanf=%s\n", c, str, sca);
    
    fclose(fp);
}

// 写入内容到文件
void writeTextFile(){
    FILE *fp;
    fp = fopen("E:\\VSCodeWorkSpace\\CCode\\baseGrammar\\test1.txt", "a");
    
    char str[] = "how are you.", prt[] = "day day up";
    
    fputc('X', fp);          // fputc(char c, FIFE *fp)
    fputs(str, fp);          // fputs(char *s, FIFE *fp)
    fprintf(fp, "%s", prt);  // fprintf(FIFE *fp, 格式字符串, char *s) 
    
    fclose(fp);
}

// 实现一次读取一行
void implReadLine(){
    FILE *fp;
    fp = fopen("E:\\VSCodeWorkSpace\\CCode\\baseGrammar\\test1.txt", "r");
    if(fp == NULL){
        printf("can not open the file.");
        exit(0);
    }
}

// 解析test文件
void parseSourceFile(){
    FILE *fp;
    fp = fopen("test.txt", "r");
}

int main(int argc, char const *argv[])
{
    //readFileText();
    writeTextFile();
    return 0;
}
