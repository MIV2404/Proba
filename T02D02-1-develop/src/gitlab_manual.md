# gitlab manual
## 1. creating a personal repository with the correct .gitignore and simple README.MD.

1. Open Terminal.
2. Create a directory to contain the project (mkdir [name directory]).
3. Go into the new directory (cd [...]).
4. Type git init.
<image src="Screen3.png" alt="git init">
5. Create a .gitignore file for your repository (touch .gitignore)
<image src="Screen1.png" alt="touch .gitignore">

### Connect it to gitlub
1. Go to gilab.
2. Log in to your account.
3. Click the new repository button in the top-right. You’ll have an option there to initialize the repository with a README file, but I don’t.
4. Click the “Create repository” button.
If you don't create README.MD autometically, you can crearte it just using command touch.

## 2. creating develop and master branches,
1. To create local master branch from exist project, use the following command:
git clone [ssh://git@repos...]
<image src="Screen4.png" alt="git clone">
You will be on master branch. You can check it by typing command git checkouheckout.
If you create a new progect (how on lesson 1), master branch will be created automatically. You can check it by typing command git checkout.

2. To create a new branch named develop, use the following command:
git checkout -b develop
<image src="Screen2.png" alt="git checkout -b develop">

## 3. setting the develop branch as the default
### Changing the default branch on Gitlab
1. On Gitlab.com, navigate to the main page of the repository.
2. Under your repository name, click  Settings. If you cannot see the "Settings" tab, select the  dropdown menu, then click Settings.
<image src="Screen5.png" alt="git checkout -b develop">
3. Screenshot of a repository header showing the tabs. The "Settings" tab is highlighted by a dark orange outline.
4. Under "Default branch", to the right of the default branch name, click .
5. Select the branch dropdown menu and click a branch name.
6. Click Update.
7. Read the warning, then click I understand, update the default branch.

## 4. creating an issue for creating the current manual,
1. On Gitlab.com, navigate to the main page of the repository.
2. Under your repository name, click  Issues.
3. Screenshot of the main page of a repository. In the horizontal navigation bar, a tab, labeled "Issues," is outlined in dark orange.
4. Click New issue.
5. If your repository uses issue templates, next to the type of issue you'd like to open, click Get started.
6. If the type of issue you'd like to open isn't included in the available options, click Open a blank issue.
<image src="Screen6.webp" alt="issue">

## 5. creating a branch for the issue,
1. On Gitlab.com, navigate to the main page of the repository.
2. Under your repository name, click  Issues.
<image src="Screen7.webp" alt="Screenshot of the main page of a repository. In the horizontal navigation bar, a tab, labeled "Issues," is outlined in dark orange>
3. In the list of issues, click the issue that you would like to create a branch for.
4. In the right sidebar under "Development", click Create a branch. If the issue already has a linked branch or pull request, select  and click Create a branch.
<image src="Screen8.png" alt="Screenshot of the issue sidebar. In the "Development" section, a link, labeled "Create a branch", is outlined in dark orange">
5. Optionally, in the "Branch name" field, type a branch name.
6. Optionally, select the Repository destination dropdown menu, then choose a repository.
7. Under "What's next", select whether you want to work on the branch locally or to open the branch in Gitlab Desktop.
8. Click Create branch.

## 6. creating a merge request on the develop branch
1. On the left sidebar, at the top, select Search GitLab () to find your project.
2. Select Code > Merge requests.
3. In the upper-right corner, select New merge request.
4. Select a source and target branch and then Compare branches and continue.
5. Fill out the fields and select Create merge request.

## 7. commenting and accepting the request,
1. Under your repository name, click  Pull requests.
2. Screenshot of the main page of a requests," is outlined in dark orange.
3. In the "Pull Requests" list, click the pull request you'd like to merge.
4. Scroll down to the bottom of the pull request.
5. If prompted, type a commit message, or accept the default message.
6. Click Confirm merge, Confirm squash and merge, or Confirm rebase and merge.
7. Optionally, delete the branch. This keeps the list of branches in your repository tidy.

## 8. creating a stable version in the master with a tag,
1. To create a tag on your current branch, run this:
git tag <tagname>
2. If you want to include a description with your tag, add -a to create an annotated tag:
git tag <tagname> -a
### Creating tags through Gitlab's web interface
1. Click the releases link on our repository page,
2. Click on Create a new release or Draft a new release,
3. Fill out the form fields, then click Publish release at the bottom,
4. After you create your tag on Gitlab, you might want to fetch it into your local repository too:
git fetch

## 9. working with wiki for the project.
If you don’t want to keep your documentation in your repository, but you want to keep it in the same project as your code, you can use the wiki GitLab provides in each GitLab project. Every wiki is a separate Git repository, so you can create wiki pages in the web interface, or locally using Git.
GitLab wikis support Markdown, Rdoc, AsciiDoc, and Org for content. Wiki pages written in Markdown support all Markdown features, and also provide some wiki-specific behavior for links.
In GitLab 13.5 and later, wiki pages display a sidebar, which you can customize. This sidebar contains a partial list of pages in the wiki, displayed as a nested tree, with sibling pages listed in alphabetical order. To view a list of all pages, select View All Pages in the sidebar.
