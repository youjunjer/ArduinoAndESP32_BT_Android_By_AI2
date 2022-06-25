# ArduinoAndESP32_BT_Android_By_AI2
[![Build Status](https://travis-ci.org/joemccann/dillinger.svg?branch=master)](https://travis-ci.org/joemccann/dillinger)


## 使用說明
**本APP由小霸王實驗室研發，主要以Android手機的藍芽連接ESP32或其他藍芽裝置
應用於物聯網課程教學或實驗，APP免費下載且開源，無需版權，非商業領域可隨意使用。**

![未命名 - 2](https://user-images.githubusercontent.com/40359899/175762204-574c4be7-d2c2-41bc-b308-794520e38d2f.jpg)


**
【六大功能介紹】

1.序列通訊：實現藍芽即時雙向通訊

2.按鈕控制：內建8組自定義按鈕控制ESP32裝置

3.方向控制：四方向及3個自定義按鈕，可實現藍芽遙控車

4.加速感測：利用手機內建的陀螺儀及加速規，實現體感遙控

5.語音指令：結合手機的Google語音辨識，實現語音智能家電

6.度量工具：將ESP32所測量的數值傳遞至手機，呈現圖表

**

-Developer Sihying, Huang & Junjer, You

## 檔案頁面

檔案中共有11個頁面視窗，以下說明名稱及對應的頁面內容

| Screen | Description |
| ------ | ------ |
| Screen1 | loading 畫面 |
| BT_SET | 按鈕控制設定主頁 |
| BT_SET_A | 按鈕內容設置頁面-名稱、數據 |
| VOICE_SET | 語音指令設定主頁 |
| VOICE_SET1 | 指令內容設置頁面-指令名稱、數據 |
| UP_SET | 方向控制設定主頁-數據 |
| Speed_SET | 加速感測器設定主頁-數據 |
| Measure_SET | 度量工具設定主頁-名稱、單位 |
| Terminal_SET | 序列通訊設定主頁-字體、外觀 |
| setting_page | 主要功能首頁區 |
| Screen2 | 操作說明頁 |

## 功能首頁區 -setting_page

AI2中藍芽功能有無法跨視窗操作的限制，因此頁面中包含了所有主要功能的指令圖塊及藍芽連結功能
並且使用元件中【可見性】屬性來解決功能區分的問題，你可以在這個頁面自由變動/取用以下功能。

1. 序列通訊功能-視窗元件、字體、外觀
2. 按鈕控制功能-按鈕元件、按鈕數量
3. 方向控制功能-按鈕元件、按鈕數量、放置位置
4. 加速感測功能-球型精靈、敏感容許值
5. 語音辨識功能-指令數量
6. 度量功能-讀取圖表外觀、數量、數值範圍

※ aia原檔中的重要圖塊，皆有相提供關的提示註解


---


### 1.序列通訊功能


**1.1在已定義的【接收訊息】程序中，可從【createMessage】指令中的【time size】【text size】變動文字訊息的大小**

![termi block1](https://snipboard.io/Q8g40k.jpg)

**1.2在已定義的【外觀顏色】程序中，可變動視窗的顏色與圖片**

![termi block1](https://snipboard.io/W48MZz.jpg)

### 2.按鈕控制功能


**2.1使用【微型資料庫】指令即可增加按鈕數量，若想讓按鈕資料可任意編輯，可在【BT_SET】及【BT_SETA】視窗中做指令設定**

![termi block1](https://snipboard.io/Ma1mEc.jpg)

**2.2取得變量中的數據索引值項目[3]後，即可透過藍芽傳送數據**

![termi block1](https://snipboard.io/pbwOVB.jpg)

### 3.方向控制功能


**3.1使用【微型資料庫】指令即可增加按鈕數量，若想讓按鈕資料可任意編輯，可在【UP_SET】視窗中做指令設定**

![termi block1](https://snipboard.io/bTkPiB.jpg)

**3.2取得指定變量中的數據後，即可透過藍芽傳送數據**

![termi block1](https://snipboard.io/vpN90m.jpg)


### 4.加速感測功能


**4.1利用球精靈移動的X,Y值判斷手機傾斜方向，調整感測數值的範圍，即可變更數據傳送的靈敏度**

![termi block1](https://snipboard.io/jL0syg.jpg)

**4.2位於中間範圍受機靜止時，將發送數據設為0，即不發送對應位置數據**

![termi block1](https://snipboard.io/QHTJ34.jpg)


### 5.語音辨識功能


**5.1使用【微型資料庫】指令即可增加語音指令數量，若想讓語音資料可任意編輯，可在【VOICE_SET】及【VOICE_SET1】視窗中做指令設定**

![termi block1](https://snipboard.io/z7Mmob.jpg)

**5.2位於中間範圍受機靜止時，將發送數據設為0，即不發送對應位置數據**

![termi block1](https://snipboard.io/L5ARox.jpg)


### 6.度量功能


**6.1使用【微型資料庫】指令即可增加度量資料的組數，若想讓度量資料可任意編輯，可在【Measure_SET】視窗中做指令設定**

![termi block1](https://snipboard.io/bdzC36.jpg)

**6.2在已定議程序【Update】中，可調整圖表外觀樣式**

![termi block1](https://snipboard.io/TjZlGF.jpg)

**6.3利用【計時器】工具可即時讀取接收的數據，多筆資料的接收需先檢查【,】字串做判讀分別顯示，並以【是否為數字?】屬性做數據處理限制**

![termi block1](https://snipboard.io/bVzGEy.jpg)

**6.4接收單一數據且數據>3個數字時 e.g.100，只顯示其一圖表數值，另個圖表數據自動設定為【0】
因此數據中可判斷有空白【 】字串且無【,】字串**

![termi block1](https://snipboard.io/IrNkvg.jpg)

**6.5接收單一數據且數據>1個數字時 e.g.24.1，只顯示其一圖表數值，另個圖表數據自動設定為【0】，因此數據中可判斷有空白【 】字串**

![termi block1](https://snipboard.io/Sty1wK.jpg)


## Licnese

MIT License

Copyright (c) 2022 youjunjer

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

[//]: # (These are reference links used in the body of this note and get stripped out when the markdown processor does its job. There is no need to format nicely because it shouldn't be seen. Thanks SO - http://stackoverflow.com/questions/4823468/store-comments-in-markdown-syntax)

   [dill]: <https://github.com/joemccann/dillinger>
   [git-repo-url]: <https://github.com/joemccann/dillinger.git>
   [john gruber]: <http://daringfireball.net>
   [df1]: <http://daringfireball.net/projects/markdown/>
   [markdown-it]: <https://github.com/markdown-it/markdown-it>
   [Ace Editor]: <http://ace.ajax.org>
   [node.js]: <http://nodejs.org>
   [Twitter Bootstrap]: <http://twitter.github.com/bootstrap/>
   [jQuery]: <http://jquery.com>
   [@tjholowaychuk]: <http://twitter.com/tjholowaychuk>
   [express]: <http://expressjs.com>
   [AngularJS]: <http://angularjs.org>
   [Gulp]: <http://gulpjs.com>

   [PlDb]: <https://github.com/joemccann/dillinger/tree/master/plugins/dropbox/README.md>
   [PlGh]: <https://github.com/joemccann/dillinger/tree/master/plugins/github/README.md>
   [PlGd]: <https://github.com/joemccann/dillinger/tree/master/plugins/googledrive/README.md>
   [PlOd]: <https://github.com/joemccann/dillinger/tree/master/plugins/onedrive/README.md>
   [PlMe]: <https://github.com/joemccann/dillinger/tree/master/plugins/medium/README.md>
   [PlGa]: <https://github.com/RahulHP/dillinger/blob/master/plugins/googleanalytics/README.md>
