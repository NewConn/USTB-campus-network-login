import requests
zm={'DDDDD':'usernum','upass':'password','0MKKey':'123456789'}
headers={'Accept':'text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,*/*;q=0.8','Accept-Encoding':'gzip, deflate, sdch','Accept-Language':'zh-CN,zh;q=0.8','Connection':'keep-alive','Cookie':'myusername=41524614; username=41524614','Host':'202.204.48.66','Referer':'http://202.204.48.66/','Upgrade-Insecure-Requests':'1','User-Agent':'Mozilla/5.0 (Windows NT 10.0; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/56.0.2924.87 Safari/537.36'}
r=requests.post('http://202.204.48.66',data=zm,headers=headers)
print(r.status_code)