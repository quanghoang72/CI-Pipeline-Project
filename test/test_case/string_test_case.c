#include <gtest/gtest.h>
#include "my_string.h"
/*TESING WITH LEN*/
TEST(strLEN,Normalletter)
{
	char s[]="HeLLo";
    EXPECT_EQ(5, my_strlen(s));
}
TEST(strLEN,Specialcharacter)
{
    char s[]="!@#$!123";
    EXPECT_EQ(8, my_strlen(s));
}
TEST(strLEN,Empty)
{
    char s[]="";
    EXPECT_EQ(0, my_strlen(s));
}
TEST(strLEN,nullpointer)
{

    char *s=NULL;
    EXPECT_EQ(-1, my_strlen(s));
}

/*TESTING WITH UPPER*/
TEST(strUPPER,Normalletter)
{
	char s[]="abcD";
 	EXPECT_EQ(3, str2upper(s));
	EXPECT_STREQ("ABCD",s);
}
TEST(strUPPER,Empty)
{
	char s[]="";
 	EXPECT_EQ(0, str2upper(s));
	EXPECT_STREQ("",s);
}
TEST(strUPPER,SpecialCharacters)
{
	char s[]="AbC12d!#$E";
 	EXPECT_EQ(2, str2upper(s));
	EXPECT_STREQ("ABC12D!#$E",s);
}
/*TESTING WITH LOWER*/
TEST(strLOWER,Normalletter)
{
	char s[]="abcD";
 	EXPECT_EQ(1, str2lower_(s));
	EXPECT_STREQ("abcd",s);
}
TEST(strLOWER,Empty)
{
	char s[]="";
 	EXPECT_EQ(0, str2lower_(s));
	EXPECT_STREQ("",s);
}
TEST(strLOWER,SpecialCharacters)
{
	char s[]="AbC12d!#$@#d";
 	EXPECT_EQ(2, str2lower_(s));
	EXPECT_STREQ("abc12d!#$@#d",s);
}
/*TESTING WITH STRIP NUMBERS*/
TEST(strNONUMBER,Normalletter)
{
	char s[]="1a21bc3";
	EXPECT_EQ(3,str_strip_numbers(s));
	EXPECT_STREQ("abc",s);
}
TEST(strNONUMBER,SpeacialCharaters){
	char s[]="0!#d31a#";
	EXPECT_EQ(5,str_strip_numbers(s));
	EXPECT_STREQ("!#da#",s);
}
/*TEST(strNONUMBER,Empty){
    char s[0];
    EXPECT_EQ(0,str_strip_numbers(s));
}*/

/*TESTING WITH COPY*/
TEST(strCPY,Normalletter)
{
    char s[]="abDE12";
	char c[20];
	mystrcpy(c,s);
    EXPECT_STREQ(s,c);
	EXPECT_STREQ("abDE12",c);
}
TEST(strCPY,Empty)
{
    char s[]="";
    char c[20];
    mystrcpy(c,s);
    EXPECT_STREQ(s,c);
	EXPECT_STREQ("",c);
}
TEST(strCPY,SpecialCharacters)
{
    char s[]="! 23ad @#$";
    char c[20];
    mystrcpy(c,s);
    EXPECT_STREQ(s,c);
	EXPECT_STREQ("! 23ad @#$",s);
}
/*TESTING WITH COMPARE*/
TEST(strCMP,Normalletter)
{
	char s[]="aBcDaB";
	char c[]="aBcEac";
	int t=mystrcmp(s,c);
	EXPECT_EQ(-4,t);
}
TEST(strCMP,SpecialCharacters)
{
    char s[]="!@#$&";
    char c[]="!@#$&z";
    int t=mystrcmp(s,c);
    EXPECT_EQ(6,t);
}
TEST(strCMP,Empty)
{
    char s[]="";
    char c[]="";
    int t=mystrcmp(s,c);
    EXPECT_EQ(0,t);
}

/*TESTING WITH DUPLICATE*/
TEST(strDUPL,Normalletter)
{
    char s[]="abDE12";
    char *c;
    c=strdupl(s);
    EXPECT_STREQ("abDE12",c);
}
TEST(strDUPL,SpecialCharacters)
{
    char s[]="!@#$!@%^&*";
    char *c;
    c=strdupl(s);
    EXPECT_STREQ("!@#$!@%^&*",c);
}
TEST(strDUPL,Empty)
{
    char s[]="";
    char *c;
    c=strdupl(s);
    EXPECT_STREQ("",c);
}


