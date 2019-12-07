#define _CRT_SECURE_NO_WARNINGS        
#include<stdio.h>    
#include<string.h>    
#include<wchar.h>//寬字元的函式庫 
#include<locale.h>//setlocale用到  
int main() 
{
 wchar_t inputline[20][50];
 int maxlen = 0;
 int i = 0;
 int k;
 int m;
 int j;
 /*  Sets locale information to be used by the current program   */
 if (!setlocale(LC_ALL, "")) //L" " :  a C wide string
 {
  fprintf(stderr, "Error:Please check LANG, LC_CTYPE, LC_ALL.\n");
  return 1;
 }
 while (fgetws(inputline[i], 50, stdin) != NULL) //input
 {    
  i++;
 }
 for (k = 0; k < i; k++) //find maxlen
 {    
  if (maxlen < wcslen(inputline[k])) 
  {
   maxlen = wcslen(inputline[k]);
  }
 }
 for (k = 0; k < i; k++)//補空格,補到和最大字串長度一樣長
 {    
  if (maxlen >= wcslen(inputline[k]))//wcslen是C寬字符串的長度
  {
   for (m = wcslen(inputline[k]) - 1; m < maxlen - 1; m++) 
   {
    inputline[k][m] = L' ';//L'  ': a C wide character
   }
   inputline[k][m] = L'\0';
  }
 }
 for (j = 0; j < maxlen - 2; j++) 
 {
  for (k = i-1 ; k >= 0; k--) 
  {
   if (iswspace(inputline[k][j])) //使用iswspace檢查空白字，如換行
   {
    wprintf(L"  ");
   }
   else 
   {
    wprintf(L"%lc", inputline[k][j]);
   }
  }
  if (j != maxlen - 2) 
  {
   wprintf(L"\n");
  }
 }
 return 0;
}