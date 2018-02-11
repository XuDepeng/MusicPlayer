# DoremiPlayer
This is just a simple music player written by C++, based on [Qt](https://www.qt.io/cn/),[taglib](http://taglib.github.io/) and [bass](http://www.un4seen.com/)

DoReMiPlayer是基于Qt C++实现的，包含歌曲播放、tag查看及编辑（暂未实现）、音效设置、歌单管理和歌词显示等功能。

# 目前实现以下模块
# 歌曲播放
使用bass库实现了本地、网络歌曲的播放，支持mp3等音乐格式的暂停、快进及快退功能。

# tag查看
使用taglib库实现了歌曲tag信息的显示，预计增加tag修改功能。

# 音效设置
使用bass库实现了歌曲的EQ（125HZ、400HZ、1kHZ、3kHZ、8kHZ、12kHZ、混响）、DSP（旋转、回声、飘忽）音效设置。

# 歌单管理
使用Qt封装的SQLite数据库，实现了歌曲、歌单的存档，预计增加对xml格式本地歌单的支持。

# 歌词显示
使用Qt的网络库和百度的api实现歌词的下载，并在tab中同步滚动显示歌词。

# 界面效果图
![image](https://github.com/XuDepeng/MusicPlayer/blob/master/screenshots/0.png)
![image](https://github.com/XuDepeng/MusicPlayer/blob/master/screenshots/1.png)
![image](https://github.com/XuDepeng/MusicPlayer/blob/master/screenshots/2.png)
![image](https://github.com/XuDepeng/MusicPlayer/blob/master/screenshots/3.png)
