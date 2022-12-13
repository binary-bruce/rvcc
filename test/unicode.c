#include "test.h"

// [226] 支持UTF-16字符字面量
#define STR(x) #x

int main() {
  printf("[224] 支持\\u和\\U转义序列\n");
  ASSERT(4, sizeof(L'\0'));
  ASSERT(97, L'a');

  ASSERT(0, strcmp("αβγ", "\u03B1\u03B2\u03B3"));
  ASSERT(0, strcmp("日本語", "\u65E5\u672C\u8A9E"));
  ASSERT(0, strcmp("日本語", "\U000065E5\U0000672C\U00008A9E"));
  ASSERT(0, strcmp("中文", "\u4E2D\u6587"));
  ASSERT(0, strcmp("中文", "\U00004E2D\U00006587"));
  ASSERT(0, strcmp("🌮", "\U0001F32E"));

  printf("[225] 支持多字节字符作为宽字符字面量\n");
  ASSERT(-1, L'\xffffffff' >> 31);
  ASSERT(946, L'β');
  ASSERT(12354, L'あ');
  ASSERT(127843, L'🍣');

  printf("[226] 支持UTF-16字符字面量\n");
  ASSERT(2, sizeof(u'\0'));
  ASSERT(1, u'\xffff'>>15);
  ASSERT(97, u'a');
  ASSERT(946, u'β');
  ASSERT(12354, u'あ');
  ASSERT(62307, u'🍣');

  ASSERT(0, strcmp(STR(u'a'), "u'a'"));

  printf("[227] 支持UTF-32字符字面量\n");
  ASSERT(4, sizeof(U'\0'));
  ASSERT(1, U'\xffffffff' >> 31);
  ASSERT(97, U'a');
  ASSERT(946, U'β');
  ASSERT(12354, U'あ');
  ASSERT(127843, U'🍣');

  ASSERT(0, strcmp(STR(U'a'), "U'a'"));

  printf("[228] 支持UTF-8字符串字面量\n");
  ASSERT(4, sizeof(u8"abc"));
  ASSERT(5, sizeof(u8"😀"));
  ASSERT(7, sizeof(u8"汉语"));
  ASSERT(0, strcmp(u8"abc", "abc"));

  ASSERT(0, strcmp(STR(u8"a"), "u8\"a\""));

  printf("[229] 支持UTF-16字符串字面量\n");
  ASSERT(2, sizeof(u""));
  ASSERT(10, sizeof(u"\xffzzz"));
  ASSERT(0, memcmp(u"", "\0\0", 2));
  ASSERT(0, memcmp(u"abc", "a\0b\0c\0\0\0", 8));
  ASSERT(0, memcmp(u"日本語", "\345e,g\236\212\0\0", 8));
  ASSERT(0, memcmp(u"🍣", "<\330c\337\0\0", 6));
  ASSERT(u'β', u"βb"[0]);
  ASSERT(u'b', u"βb"[1]);
  ASSERT(0, u"βb"[2]);

  ASSERT(0, strcmp(STR(u"a"), "u\"a\""));

  printf("[230] 支持UTF-32字符串字面量\n");
  ASSERT(4, sizeof(U""));
  ASSERT(20, sizeof(U"\xffzzz"));
  ASSERT(0, memcmp(U"", "\0\0\0\0", 4));
  ASSERT(0, memcmp(U"abc", "a\0\0\0b\0\0\0c\0\0\0\0\0\0\0", 16));
  ASSERT(0, memcmp(U"日本語", "\345e\0\0,g\0\0\236\212\0\0\0\0\0\0", 16));
  ASSERT(0, memcmp(U"🍣", "c\363\001\0\0\0\0\0", 8));
  ASSERT(u'β', U"βb"[0]);
  ASSERT(u'b', U"βb"[1]);
  ASSERT(0, U"βb"[2]);
  ASSERT(1, U"\xffffffff"[0] >> 31);

  ASSERT(0, strcmp(STR(U"a"), "U\"a\""));

  printf("OK\n");
  return 0;
}