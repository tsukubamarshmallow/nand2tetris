# コンピューターシステムの理論と実装(OREILLY）

### 1章 基本論理ゲートを用いたブール論理ゲートの作成

Not,And,Or,Xor(基本論理ゲート)をNadnゲートで実装

Mux,DMuxは基本論理ゲートを用いて実装

1入力nビット1出力1ビット論理ゲートについてはOr8wayを実装

多入力nビット多出力nビット論理ゲートについてはMux16-4way,Mux16-8way,DMux4way,DMux8wayを実装

今後の高階層の実装においては1章で作成したコンポネントを組み合わせることで実装することが出来る

学習終了日 2024/02/20

学習所要時間 3時間

### 2章 ブール算術(ALUの実装)

2の補数表現によって足し算と引き算を等価に扱うことが出来るようになる

2の補数表現では最上位bitが1ならば負,0ならば正と判断することが出来る

ある数xに対して-xはxについて下位ビットから探査し、初め1と出会う位より上位の位についてbit反転することによって表現することが出来る

半加算機(2bit)、全加算器(3bit)、加算器(16bit)の実装及びインクリメンタの実装

ALUは16bit2入力16bit1出力(計算結果),1bit2出力(out[16]==0かの判断およびout[16] < 0 の判断　←　アセンブリ言語でもこのフラグは高級言語におけるラベル移動に使用された為恐らく例に当てはまる)から構成されていて、

入力の反転,入力の零化,And16,Add16,出力の反転を機能に持つ

具体的な実装方法はMux16とその他論理ゲートから構成される

学習終了日 2024/02/20

学習所要時間　1.5時間

### 3章　順序回路(RAM,PCカウンターの作成)

DFFを最小構成要素としてRegister,RAM8,RAM64...,PCcounterを作成

回路内にこれらの記憶素子を組み合わせ回路と共に取り込むことによって回路全体が記憶を保持しながら演算することが出来るようになる

DFF→Register→RAM8→RAM64→.....どんどん高階層にしていけば容量の多いRAMを作成することが出来る

学習終了日 2024/02/21

学習所要時間 1.5時間

### 4章　機械語(fill.asm 未完)

コンピュータの内部構成を考えた時にCPUやメモリから全容を語ることが出来るがより抽象的で簡易的に語ることが出来る

それは機械語からコンピューター全容を語ることである

機械語の命令セットと文法を詳しく見ればそれを実現させるためのコンピューター内部での仕組みが分かる

ハードウェアにはデータメモリと命令メモリ、マップドI/O(周辺機器に関する領域)が存在している

本書籍で利用される機械語Hackの仕様はcomp領域,dest領域,jump領域からなる

またそれに対応したアセンブリ言語ではA命令(アドレスレジスタに対する操作)とC命令(データレジスタに対する操作)が存在している

学習終了日 hoge/hoge/hoge

学習所要時間 2.5時間

### 5章　コンピューターシステム

#### 5章1節　CPU

16bit命令のHack機械語の仕様に従ってCPUを設計する

命令コードは[0]A命令orC命令[3]compニーモニック[4..9]ALU演算[10..12]dest領域[13..15]jump領域から構成される

[0]は主にAレジスタに値を格納するのか、ALUでの演算を要するのか決定する際に使用される

[3]は演算する際にAとM[A]のいずれかを使用するのか決定する際に使用される

[4..9]はALUで実行する関数を決定する際に使用される

[10..12]はALUの演算結果をどこに格納するか決定する際に使用される

[13..15]はpcカウンタの値を書き込み,リセット,インクリメントいずれの方法を取るか決める際に使用される

学習終了日 2024/02/22

学習所要時間 4.0時間

#### 5章2節　メモリー

メモリの全体設計はデータメモリ(RAM16K,screenRAM,KeyboardRAM),命令メモリ(ROM32K)から構成される

学習終了日 2024/02/22

学習所要時間 0.3時間

#### 5章3節　コンピューター

作り上げたCPUとメモリを接続し、hack機械語をハードウェア上で実行できるようにする

学習終了日 2024/02/24

学習所要時間 0.2時間

#### 1~5章まとめ

1~5章では機械語Hackの命令コードをハードウェア上で実行できるようにコンピューターを実装した

実際に基本的な論理ゲートを複雑化させていく事によって、人間の思考に限りなく近い命令を機械語として処理することが出来るようなノイマン型コンピューターを実装する事が出来た

次章以降は機械語からアセンブリ言語へつながっていく

### 6章　アセンブラ

#### Paese-moduleの実装

### Code-write-moduleの実装

学習所要時間 3.0 + 3.0(環境構築) + 1.0　+ 2.0  + 3.6 = 12.5時間

学習終了日 2024/02/24

### 7章　VM(前半)
VM(前半)の実装では、高水準言語からコンパイルされたVM言語(コンパイルについては10~11章で取り扱う)を、アセンブリ言語に変換する事を目標とする。
7章ではVM言語のメモリアクセスコマンドと算術コマンドをアセンブリ言語にマッピングする。
そのためこの章を開始する前に予めアセンブリ言語の仕様と機械語の仕様について復習する必要がある。

#### 機械語Hackのおさらい

16bitの命令コードから構成される。
そのため、アドレス指定と算術演算を同時に実行することが出来ない。
このことからアドレス指定と算術演算は1行の命令コードから実行される。
アドレス指定をA命令、算術演算をC命令と呼ぶ。
C命令は(flag,comp(算術式),dest(評価された算術式の送り先),jump(条件分岐))から構成される。

#### アセンブリ言語Hackのおさらい

基本的には機械語Hackにラベルを当てたものと考えることが出来る。
しかし、機械語の時点で存在しなかった概念が存在しており、それがシンボルである。
シンボルは@i,@sumのような文字列で表現され、プラットフォーム上のメモリの16番地から順次割り当てが実行される。
メモリ番地の割り当てはアセンブラーが処理をする。
　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　
#### Parse-moduleの実装
学習終了　2024/04/20 4hour

#### Code-write-moduleの実装
・算術演算の結果はMに代入すれば良さそう？
・ハードウェア上のスタック領域をどうやって割振るのか






