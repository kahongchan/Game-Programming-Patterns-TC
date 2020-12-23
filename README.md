# [遊戲編程模式繁體中文版](http://gpps.billy-chan.com/)
###### 點擊上面標題在線閱讀

## 關於此書
此書的翻譯文本原作者是 [Milo Yip](https://github.com/miloyip), 並由 [tkchu](https://github.com/tkchu) 分享, 本人只是以一位左手交右手的角色將此書轉換成繁體中文, 目的只是想將此好書分享給繁體社群. 並增加少許功能如加入 TOC (原文版有此功能) 和作少許修正. 在此十分感謝原作者 Bob Nystrom 和翻譯的 Milo Yip 及 tkchu 無私貢獻. 

由於文本和執行腳本均有作出修改, 所以已將 python 2.7 的腳本移除. 請使用 Python 3 或以上執行腳本. 

《遊戲編程模式》是由曾在EA工作八年的Bob Nystrom寫就，講述在遊戲開發中各種常見的編程模式。
通過閱讀此書，可以更好的理解設計模式和工程化開發。

英文版在線閱讀：[Game Programming Patterns](http://gameprogrammingpatterns.com/)

Bob Nystrom同時在Github上無私地提供原本：[munificent/game-programming-patterns](https://github.com/munificent/game-programming-patterns)。

如果有任何表意不明或者疏忽遺漏，歡迎提出Issues，謝謝您的貢獻，讓我們的世界變得更好。

## 編譯本書

這本書使用Markdown寫就(`book/`)。使用了一些Python腳本(`script/format.py`)、SASS文件(`asset/style.scss`)及HTML模板(`asset/template.html`)轉換爲最終的HTML文件(`html/`)。想要自行編譯，需要安裝Python，以及Python Markdown, Pygments,和SmartyPants (可能需要使用sudo指令或者管理員權限。):

	$ pip install markdown
	$ pip install pygments
	$ pip install smartypants


在此之後，使用：

	$ python script/format.py 

請從本項目的根目錄運行該腳本，本腳本也可以以監視模式運行：

	$ python script/format.py --watch

這會監視對markdown文件，SASS文件或HTML模板的修改，並生成必要的文件。
