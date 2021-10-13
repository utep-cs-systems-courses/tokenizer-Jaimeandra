#include <stdio.h>
#include <string.h>

int space_char(char c)
{
  if(c == ' ' || c == '\n' || c == '\t')
    return 1;
  else
    return 0;
}

int non_space_char(char c)
{
  if(c == ' ' || c == '\n' || c == '\t')
    return 0;
  else
    return 1;
}

int count_words(char *str)
{
  int count = 0;
  int length = strlen(str);
  for(int i =0; i < length; i++)
    {
      if(space_char(str[i]) == 1 && non_space_char(str[i-1]) == 0 || non_space_char(str[i+1]) == 0)
	// making sure its just a space inbetween words
	{
	  count+=1;
	}      
    }
  return count+1;
}

char *word_start(char *str,int j)
{
  char *word;
  int length = strlen(str);
  for(int i =j ; i < length; i++)
    {
      if(non_space_char(str[i])== 1)
	{
	  word = &str[i];
	  return word;
	}
    }
}

char *word_end(char *str,int j)
{
  int length = strlen(str);
  char *word;
  for(int i = j; i < length; i++)
    {
      if(space_char(str[i]))
	{
	  word = &str[i];
	  return word; 
	}
    }
}

char *copy_str(char *src, short len)
{
  static char temp[20];
  for(int i =0; i < len; i++)
    {
      temp[i] = src[i];
    }
  return (temp);
}

void print_tokens(char **tokens)
{

}

char *get_tokens(char **tokens, int id)
{
  
}

char **tokenize(char *str)
{
  int words = count_words(str);
  int length = strlen(str);
  //char tokens[5][20];
  // got confused with this and was running out of time :(
  char* start = NULL;
  //necessary for the start
  char* end = NULL;

  for(int i =0; i < length; i++)
    {
      if(start == NULL || &str[i-1] == end)
	{
	  start = word_start(str,i);
	  //will be used for grabbing the word
	  end = word_end(str,i);
	}
      if(&str[i] == start)
	{
	  char temp[20] = " ";
	  for(int j = i; end != &str[j]; j++)
	    {
	      strncat(temp,&str[j],1);
	      //add character to string
	    }
	  printf("%s\n",temp);
	  //show the string
	}
    }
}

int main(void)
{
  char *gets(char *str);
  char str[50];
  fgets(str,50,stdin); //grab string from user
  tokenize(str);
}
