# git 初始化
```shell
git config --global user.name "mac"
git config --global user.email"a0979552111@gmail.com"
```
# git 忽略檔案
新增檔案名稱為`.gitignore` 內容可以參考[此連結](https://www.freecodecamp.org/chinese/news/gitignore-file-how-to-ignore-files-and-folders-in-git/)，改完`.gitignore`後，使用底下指令
```shell
#先新增
git add .gitignore

```
```shell
#後提交
git commit -m "update ignored files"

```
# 添加远程仓库地址到本地仓库

 
```shell
git remote add origin {远程仓库地址}
# Sets the new remote
git remote -v
# Verifies the new remote URL
 ```

# push到远程仓库
```shell
git branch -M main
git push -u origin main
# Pushes the changes in your local repository up to the remote repository you 
```