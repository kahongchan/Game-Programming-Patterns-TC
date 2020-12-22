^title 優化模式 Optimization Patterns

雖然越來越快的硬件解除了大部分軟件在性能上的顧慮，對遊戲來說卻並非如此。
玩家總是想要更豐富、真實、激動人心的體驗。
到處都是爭搶玩家注意力——還有金錢——的遊戲，能將硬件的功能發揮至極致的遊戲往往獲勝。

優化遊戲性能是一門高深的藝術，要接觸到軟件的各個層面。
底層程序員掌握硬件架構的種種特質。同時，算法研究者爭先恐後地證明誰的過程是最有效率的。

這裏，我描述了幾個加速遊戲的中間層模式。
[數據局部性](data-locality.html)介紹了計算機的存儲層次以及如何使用其以獲得優勢。
[髒標識](dirty-flag.html)幫你避開不必要的計算。
[對象池](object-pool.html)幫你避開不必要的內存分配。
[空間分區](spatial-partition.html)加速了虛擬世界和其中元素的空間佈局。

## 模式

* [數據局部性](data-locality.html)
* [髒標識](dirty-flag.html)
* [對象池](object-pool.html)
* [空間分區](spatial-partition.html)
