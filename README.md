# [遊戲編程模式繁體中文版](http://tkchu.github.io/Game-Programming-Patterns-CN/)
###### 點擊上面標題在線閱讀

《遊戲編程模式》是由曾在EA工作八年的Bob Nystrom寫就，講述在遊戲開發中各種常見的編程模式。
通過閱讀此書，可以更好的理解設計模式和工程化開發。

英文版在線閱讀：[Game Programming Patterns](http://gameprogrammingpatterns.com/)

Bob Nystrom同時在Github上無私地提供原本：[munificent/game-programming-patterns](https://github.com/munificent/game-programming-patterns)。

如果有任何表意不明或者疏忽遺漏，歡迎提出Issues，謝謝您的貢獻，讓我們的世界變得更好。

## 進度

1. 第一輪作業（完成）：將整書翻譯一遍，翻譯質量預期略高於谷歌機翻。
2. 第二輪作業（完成）：修復漏洞，翻譯所有的旁註並添加鏈接，同時平滑語言。
3. 第三輪作業（完成）：校訂，修改圖片爲中文，將alt也改爲中文。
4. 第四輪作業（完成）：修改代碼註釋爲中文。
5. 第五輪作業：優化訪問速度和顯示效果。
    - 通過使用百度CDN提供jquery（完成）。
    - 刪除google analysis代碼（完成）。
    - 刪除英文特殊字體（完成）。
    - 壓縮圖片（完成）。
    - 使用更適合中文的CSS設置（完成）。

## 編譯本書

這本書使用Markdown寫就(`book/`)。使用了一些Python腳本(`script/format.py`)、SASS文件(`asset/style.scss`)及HTML模板(`asset/template.html`)轉換爲最終的HTML文件(`html/`)。想要自行編譯，需要安裝Python，以及Python Markdown, Pygments,和SmartyPants (可能需要使用sudo指令或者管理員權限。):

	$ pip install markdown
	$ pip install pygments
	$ pip install smartypants


在此之後，使用：

	$ python script/format.py # Python 3

或者

	$ python script/format_python2.py # Python 2.7+

請從本項目的根目錄運行該腳本，本腳本也可以以監視模式運行：

	$ python script/format.py --watch

這會監視對markdown文件，SASS文件或HTML模板的修改，並生成必要的文件。
