#@# vim:set expandtab tabstop=2 shiftwidth=2 softtabstop=2 autoindent smartindent:

= HTMLの章 見出し(1) : リード文

//lead{
HTMLでのリード文(1)
HTMLでのリード文(1)

HTMLでのリード文(1)
HTMLでのリード文(1)
//}

== HTMLの節 見出し(1) : 箇条書きサンプル

箇条書き：

 * item1
 * item2
 ** item2-1
//emlist{
  リスト中にはemlist入れられなかった・・・。
  ここで、liとul要素が閉じられてしまうので、
  <li>... <div><p><pre>...</pre></p></div> ... </li>
  とはならずに、
  <li>... </li></ul>
  <div><p><pre>...</pre></p></div>
  <ul><li> ...
  と分割されてしまう・・・。
//}
 ** item2-2
 *** item2-2-1
 *** item2-2-2
 **** item2-2-2-1
 **** item2-2-2-2
 * item3

箇条書き番号付き(番号付きはネスト不可)：

 1. item1
 2. item2
 3. item3

 1. とりあえず @<code>{ 1. } で揃えておけば、 @<code>{ <ol> - <li> } になるため自動で1から連番になります。
 1. とりあえず @<code>{ 1. } で揃えておけば、 @<code>{ <ol> - <li> } になるため自動で1から連番になります。
 1. とりあえず @<code>{ 1. } で揃えておけば、 @<code>{ <ol> - <li> } になるため自動で1から連番になります。

==[column] HTMLの節レベルのコラム(1) : 識別子で参照できるリスト例

HTMLの節レベルのコラム(1)
HTMLの節レベルのコラム(1)

//listnum[src-main][main.c][c]{
#include <stdio.h>

int main(int argc, char *argv[]) {
  printf("Hello, World!\n");
  return 0;
}
//}

==[/column]

=== HTMLの項 見出し(1) : 表の例

表の例：

//table[envvars][重要な環境変数]{
名前            意味
-------------------------------------------------------------
PATH            コマンドの存在するディレクトリ
TERM            使っている端末の種類。linux・kterm・vt100など
LANG            ユーザのデフォルトロケール。日本語ならja_JP.eucJPやja_JP.utf8
LOGNAME         ユーザのログイン名
TEMP            一時ファイルを置くディレクトリ。/tmpなど
PAGER           manなどで起動するテキスト閲覧プログラム。lessなど
EDITOR          デフォルトエディタ。viやemacsなど
MANPATH         manのソースを置いているディレクトリ
DISPLAY         X Window Systemのデフォルトディスプレイ
//}

===[column] HTMLの項レベルのコラム(1) : 識別子で参照できないリスト例

HTMLの項レベルのコラム(1)
HTMLの項レベルのコラム(1)

//emlistnum[main()][c]{
#include <stdio.h>

int main(int argc, char *argv[]) {
  printf("Hello, World!\n");
  return 0;
}
//}

===[/column]

==== HTMLの段 見出し(1) : 引用の例

引用の例：

//quote{
  こんにちは
  こんばんは
  ハロー
//}

===== HTMLの少段 見出し(1) : 脚注の例

こんにちは、サンプルサイト@<fn>{exsite}を御覧ください。

//footnote[exsite][一般的なサンプルサイトURL : http://www.example.com]

= HTMLの章 見出し(2) : リード文

//lead{
HTMLでのリード文(2)
HTMLでのリード文(2)

HTMLでのリード文(2)
HTMLでのリード文(2)
//}

== HTMLの節 見出し(2) : 箇条書きサンプル2

箇条書き番号付き(番号付きはネスト不可)：

 1. item1
 2. item2


 3. 番号付きを、途中から始めようとしても、ol要素のstart属性に反映されないため、1から振り直しになります・・・。
 3. 番号付きを、途中から始めようとしても、ol要素のstart属性に反映されないため、1から振り直しになります・・・。
 3. 番号付きを、途中から始めようとしても、ol要素のstart属性に反映されないため、1から振り直しになります・・・。

==[column] HTMLの節レベルのコラム(2) : 識別子で参照できるリスト例

HTMLの節レベルのコラム(2)
HTMLの節レベルのコラム(2)

//listnum[src-main2][main.c][c]{
#include <stdio.h>

int main(@<u>{int argc, char *argv[]) {}
  printf("@<i>{Hello, World!}\n");
  return 0;
}
//}

==[/column]

=== HTMLの項 見出し(2) : 表の例

表の例：

//table[envvars2][重要な環境変数]{
名前            意味
-------------------------------------------------------------
PATH            コマンドの存在するディレクトリ
TERM            使っている端末の種類。linux・kterm・vt100など
LANG            ユーザのデフォルトロケール。日本語ならja_JP.eucJPやja_JP.utf8
LOGNAME         ユーザのログイン名
TEMP            一時ファイルを置くディレクトリ。/tmpなど
PAGER           manなどで起動するテキスト閲覧プログラム。lessなど
EDITOR          デフォルトエディタ。viやemacsなど
MANPATH         manのソースを置いているディレクトリ
DISPLAY         X Window Systemのデフォルトディスプレイ
//}

===[column] HTMLの項レベルのコラム(2) : 識別子で参照できないリスト例

HTMLの項レベルのコラム(2)
HTMLの項レベルのコラム(2)

//emlistnum[main()][c]{
#include <stdio.h>

int main(int argc, char *argv[]) {
  printf("Hello, World!\n");
  return 0;
}
//}

===[/column]

==== HTMLの段 見出し(2) : 引用の例

引用の例：

//quote{
  こんにちは
  こんばんは
  ハロー
//}

===== HTMLの少段 見出し(2) : 脚注の例

こんにちは、サンプルサイト@<fn>{exsite}を御覧ください。

