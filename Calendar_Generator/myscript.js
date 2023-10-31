const d = new Date();
var current_date=d.getDate();
var current_day=d.getDay();
var current_month=d.getMonth();
var current_year=d.getFullYear();

var total_days=0;
var leap_year=true;
var year=current_year;

var inputYear=parseInt(document.getElementById("enter-year").value);
console.log(typeof inputYear)
var inputMonth=parseInt(document.getElementById("months").value);

var s = new Date(`${current_year}-${current_month+1}-1`);
var start_date=s.getDay();

// Check leap year
if(year%4==0){
    if(year%100==0){
        if(year%400==0){
            console.log(year,"is a leap year.");
            leap_year=true;
        }else{
            console.log(year,"is not a leap year.");
            leap_year=false;
        }
    }else{
        console.log(year,"is a leap year.");
        leap_year=true;
    }
}else{
    console.log(year,"is not a leap year.")
    leap_year=false;
}

function updateMonth(){
    const arr_month=["January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"];
    document.getElementById("month-name").innerHTML=arr_month[current_month];
}

// Count total days
function updateTotalDays(){
    var month=current_month;
    if(month==0 || month==2 || month==4 || month==6 || month==7 || month==9 || month==11){
        total_days=31;
    }else if(month==1){
        if(leap_year){
            total_days=29;
        }else{
            total_days=28;
        }
    }else{
        total_days=30
    }
}

// Current date check and highlight
var targetID=current_date;
document.getElementById(targetID).style.backgroundColor='#AEDEFC';

// Assign dates to calender
function renderDates(){
    for(let a=0; a<42; a++){
        document.getElementById(a+1).innerHTML="";
    }
    for(let i=1; i<=total_days; i++){
        document.getElementById(start_date+1).innerHTML=i;
        start_date++;
    }
    
}

updateMonth();
updateTotalDays();
renderDates();

function prev(){
    current_month--;
    if(current_month<0){
        current_month=0;
    }
    updateMonth();
    updateTotalDays();
    s = new Date(`${current_year}-${current_month+1}-1`);
    start_date=s.getDay();
    renderDates();
    document.getElementById(targetID).style.backgroundColor='white';
}

function next(){
    current_month++;
    if(current_month>11){
        current_month=11;
    }
    updateMonth();
    updateTotalDays();
    s = new Date(`${current_year}-${current_month+1}-1`);
    start_date=s.getDay();
    renderDates();
    document.getElementById(targetID).style.backgroundColor='white';
}

function generate(){
    current_month=parseInt(document.getElementById("months").value);
    current_year=parseInt(document.getElementById("enter-year").value);
    updateMonth();
    updateTotalDays();
    s = new Date(`${current_year}-${current_month+1}-1`);
    start_date=s.getDay();
    renderDates();
    document.getElementById(targetID).style.backgroundColor='white';
    console.log(current_year, current_month);
}

console.log(s);