var eqn="";
var n;
var count=0;

function calc(data){
    if(data=='+'||data=='-'||data=='*'||data=='/'||data=='%'){count+=1;}
    else{count=0;}
    if(count>1){
         del();
        count-=1;
    }
    eqn+=data;
    n=eqn.length;
    document.getElementById("result").innerHTML=eqn;
    console.log(eqn);
}

function equal(){
    let position=-1;
    position=eqn.indexOf('%');
    if(position!=-1){
        percentage();
        return;
    }
    var result=eval(eqn);
    document.getElementById("result").innerHTML=result;
    eqn=result;
    console.log(eqn);
}

function allClear(){
    eqn="";
    document.getElementById("result").innerHTML=eqn;
    console.log(eqn);
}

function del(){
    let temp=eqn.slice(0,n-1);
    eqn=temp;
    n=eqn.length;
    document.getElementById("result").innerHTML=eqn;
    console.log(eqn);
}

function percentage(){
    const arr=eqn.split("%");
    let percent=(eval(arr[0])/100)*eval(arr[1]);
    eqn=percent;
    document.getElementById("result").innerHTML=eqn;
}