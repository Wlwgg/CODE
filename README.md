# CODE

考研数据结构与算法的实现

## 步骤
### 1.    
下载git工具git的安装就不再赘述了，在git工具下载后，按默认直接安装即可。
### 2.
绑定github打开安装好的 Git Bash 输入以下命令：
  ```
  $ git config --global user.name "YiyiF"
  $ git config --global user.email "yiyifu97@gmail.com"
  Note: name 和 email 为注册github 的用户名及邮箱地址。
```
### 3. 
建立repository在github建立新的仓库，如图，直接点击New，按照指示即可建立成功。Note: README可选添加或不添加。一些博主建议添加，但我尝试几次之后发现，上传文件前建立的README在按照此方法上传后总是不存在了。不过在上传一次后仍可继续添加README文件，并未发现此种方法的缺点，也没有找到解决发放。由于原因还没有找到，看到文章的您如果知道可留言给我，谢谢。
  新建repository
  我新建了一个upload_folders的仓库，接下来的演示都基于此仓库。
### 4.
设置SSH key
#### 4.1    生成密钥输入以下命令来生成密钥，保存路径直接回车即可保存在默认路径。
```
$ ssh-keygen -t rsa -C "yiyifu97@gmail.com"
```
  设置 SSH key生成成功后，去对应目录用记事本打开id_rsa.pub，得到ssh key公钥，复制下来。下面就可以去github来配置SSH key了。
 #### 4.2 
 为github账号配置SSH key点开头像展开小三角，点击Settings，选择SSH and GPG keys，接着点击 New SSH key，将之前复制的公钥填至对应Key一栏即可。
  添加SSH key
 ### 5.   
 上传本地文件至github
 #### 5.1 
 本地文件我已创建了一个test文件夹，里面有两个文件夹，分别包含一个简单的.py文件。Note: 要上传的文件夹为test_1和test_2，需要一次上传的文件夹在一个目录下可以一次上传。
 #### 5.2 
 通过Git上传文件Step 1：建立本地仓库按顺序在Git Bash执行以下指令：Note: cd 为文件路径；git init会在此文件夹生成一个.Git隐藏文件；git add . 会上传所有文件；git commit 添加注释。
  ```
  $ cd d:text
  $ git init
  $ git add .
  $ git commit -m "这里是注释"
  ```
  Step 2：上传文件至github打开仓库，点击Clone or download复制下面的地址，然后执行下面的指令：Note: git remote add origin后为所复制的仓库地址；git push -u origin master命令即可上传本地代码。
  ```
  $ git remote add origin https://github.com/YiyiF/upload_folders.git
  $ git push -u origin master
  ```
  Git Bash输入命令
  此处可以看到，有可能会出现error。但按以下方法可以解决：注意到提示有说输入 git pull 即可解决，因此首先输入```git pull ```命令，然后输入```git push origin master -f```命令。显示100%，done即为上传成功，注意到To后的地址就是我们要上传文件的仓库。
 ### 6.  
 更新仓库文件如果我们后期对本地文件有了修改，则需要对仓库文件进行更新。此时我在本地文件test_1里新添加了一个update.py的文件。下面将显示如何对仓库更新，将新添加的文件上传至仓库。首先还是在Git Bash中打开文件目录，然后输入命令git status，此时可以看到有做修改的文件。接着输入命令git add -A，此命令为上传所有修改，注意此时的注释的命令应为```git commit -a -m "update```，引号内为注释。下面注意上传文件的命令使用git push可能会出错，所以输入
``` git push origin master -f```即可更新成功。
##  总结
```
  $ cd e:test
  $ git status
  $ git add -A
  $ git push origin master -f
```

