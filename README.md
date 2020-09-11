# sublime-text-config-for-oi
My own configuration file of Sublime Text 3 for OI learning.

这个项目是一个配置参考，用于分享我在 macOS 下为 OI 学习使用的 Sublime Text 3 配置。本意是提供类似 Dev C++ 的编程体验，以及方便日常使用。

#### 编译系统（`G++.sublime-build`）

默认选项是编译 & 运行，支持选择不同 C++ 标准编译。

为了尽可能提供仿真的体验，我重构了 Dev C++ 的 ConsolePauser 源码以在 macOS 下运行。并使用 Apple Script 调用 Terminal.app 或 iTerm2.app 运行。

此处用到的 ConsolePauser 源码放在 `ConsolePauser.cpp` 文件中，请自行编译并放到 `/usr/local/bin` 中。

#### 快捷键配置（`OI.sublime-keymap`）

提供了一些在 Dev C++ 下常用的快捷键（如 `Ctrl + D` 删除整行）。以及将 `f9`、`f10`、`f11` 绑定到上述的编译运行命令。

只做了一部分，希望起到抛砖引玉的作用，有老哥完善了的话欢迎提个 PR（thx