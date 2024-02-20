コンピューターシステムの理論と実装(OREILLY）

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

学習終了日 2024/02/24 

学習所要時間　1.5時間
