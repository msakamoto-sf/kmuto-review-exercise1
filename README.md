# kmuto-review-exercise1

Re:VIEW の練習その1です。

 * kmuto/review: Re:VIEW is flexible document format/conversion system
   * https://github.com/kmuto/review

# 実験環境

```
CentOS7 (64bit)

ruby 2.3.1p112 (2016-04-26 revision 54768) [x86_64-linux]
review (2.0.0)
```

TeX環境 : 以下の記事参考にTeX Live 2016をインストール。

 * 参考メモ/CentOS7に TeX Live 2016 をインストールして簡単な動作確認をする - Qiita
   * http://qiita.com/msakamoto_sf/items/78c322cb8656615ce134

## rbenv, ruby-buildインストール

OSパッケージのRubyと衝突しないよう、rbenvとruby-buildをインストールします。

### rbenvのインストール

see : https://github.com/rbenv/rbenv#installation

```
$ git clone https://github.com/rbenv/rbenv.git ~/.rbenv
$ echo 'export PATH="$HOME/.rbenv/bin:$PATH"' >> ~/.bashrc
$ ~/.rbenv/bin/rbenv init

-> 表示された内容を .bashrc に追記：
$ echo 'eval "$(rbenv init -)"' >> ~/.bashrc

-> シェルに入り直して、rbenvコマンドのインストールチェック
$ type rbenv
rbenv is a function
rbenv ()
{
(...)
}
```

### ruby-buildのインストール

see : https://github.com/rbenv/ruby-build/

ruby-buildでRubyのビルドに必要な共有ライブラリパッケージをインストール (see : https://github.com/rbenv/ruby-build/wiki ):

```
$ sudo yum install -y gcc bzip2 openssl-devel libyaml-devel libffi-devel readline-devel zlib-devel gdbm-devel ncurses-devel
```

ruby-buildのインストール:

```
$ git clone https://github.com/rbenv/ruby-build.git ~/.rbenv/plugins/ruby-build
```

インストール可能なRubyバージョンの一覧確認:

```
$ rbenv install -l
```


Ruby 2.3.1 をインストールと、動作確認:

```
$ rbenv install 2.3.1
(...)

$ rbenv shell 2.3.1
$ rbenv version
2.3.1 (set by RBENV_VERSION environment variable)
$ ruby --version
ruby 2.3.1p112 (2016-04-26 revision 54768) [x86_64-linux]
```

rbenvのRuby 2.3.1環境を準備できた。

## Re:VIEWのインストール

rbenv/ruby-buildでインストールした 2.3.1 環境にそのまま `gem install` しても良いが、プロジェクトごとに使うライブラリを分離できた方が後々楽なので、bundlerを使う。

bundler自身を 2.3.1 環境にインストール:

```
$ rbenv shell 2.3.1
$ gem install bundler
$ rbenv rehash
$ rbenv which bundle
/home/msakamoto/.rbenv/versions/2.3.1/bin/bundle
$ bundle --version
Bundler version 1.13.1
```

Re:VIEW を試すためのディレクトリを作成してその中にcdし、bundlerからRe:VIEWのgemをインストールする。

今回は先に本リポジトリをGitHub上で作成し、それをclone:

```
$ git clone git@github.com:msakamoto-sf/kmuto-review-exercise1.git
```

このディレクトリのlocalで rbenv 2.3.1 を指定:

```
$ rbenv local 2.3.1
$ git add .ruby-version
$ git commit -m 'add rbenv local .ruby-version for Ruby 2.3.1'
```

初期化 -> インストール:

```
$ bundle init
Writing new Gemfile to /home/msakamoto/github/msakamoto-sf/kmuto-review-exercise1/Gemfile
$ cat << EOF > Gemfile
source "https://rubygems.org"

gem "review"
EOF

$ bundle install --path vendor/bundle

$ bundle list
Gems included by the bundle:
  * bundler (1.13.1)
  * review (2.0.0)
  * rubyzip (1.2.0)

$ git add Gemfile Gemfile.lock
$ git commit -m 'add Gemfile, Gemfile.lock'
```

## 動作確認

プロジェクト作成:

```
$ bundle exec review-init hello
$ find hello
hello
hello/catalog.yml
hello/hello.re
hello/images
hello/images/cover.jpg
hello/layouts
hello/style.css
hello/sty
hello/sty/reviewmacro.sty
hello/config.yml
hello/Rakefile
```

PDF作成：

```
$ cd hello
$ bundle exec review-pdfmaker config.yml
```

-> 無事、デフォルトの `book.pdf` が生成された。

# 練習プロジェクトの紹介と簡単な解説

## ex1-catalog-and-heading

`catalog.yml` と、見出しで色々組み合わせたデモです。

```
$ bundle exec review-init ex1-catalog-and-heading

$ cd ex1-catalog-and-heading
$ bundle exec review-pdfmaker config.yml
```

# 参考資料

本家GitHubのWikiが日本語でわかりやすくまとめられてます。

 * https://github.com/kmuto/review/wiki

他にも開発者自身を含めて紹介記事も多く、参考になります。触り始めたころに参考にした記事は以下になります：

 * Re:VIEW の使い方 - A Day in Serenity @ kenjis
   * http://d.hatena.ne.jp/Kenji_s/20110927/1317105278
 * 書籍制作フローを変える。「ReVIEW」という解。～マークアップと自動組版と、時々、電子書籍～, 武藤 健志
   * http://kmuto.jp/events/page2012/page2012.pdf
 * 【書籍制作ワークフロー】ReVIEW 入門 #01 – ReVIEW をインストール ｜ Developers.IO
   * http://dev.classmethod.jp/tool/try-review-01/
 * 書籍執筆支援システム「ReVIEW」に触ってみた話（＆リンク集） - the code to rock
   * http://note103.hateblo.jp/entry/2014/02/10/175440

