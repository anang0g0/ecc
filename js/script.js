var cgi_path = './perl.cgi?param=';
var handleContent;
var req;
var TextNode;
var counter = 0;

function proc_onload() {
req = new XMLHttpRequest();
handleContent = document.getElementById('content');
var anc = document.getElementById('reload');
anc.onclick = reqdata;
var text = document.createTextNode('');
TextNode = handleContent.appendChild(text);
}


//送信要求用関数
function reqdata() {
req.onreadystatechange = proc_readdata;
req.open("get",cgi_path + counter, true);
req.send("");
++counter;
}

//受信用関数
function proc_readdata() {
if(req.readyState == 4) {
var text = document.createTextNode(req.responseText);
handleContent.removeChild(TextNode);
TextNode = handleContent.appendChild(text,TextNode);
}
}

window.onload=proc_onload;
