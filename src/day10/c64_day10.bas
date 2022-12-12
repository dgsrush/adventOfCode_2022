new
10 let cyc=0
11 let x=1
12 let ans=0
13 let rast=0
100 open 1,8,2,"aocinp,seq,r"
110 input#1,ss$
121 if ss$="noop" then gosub 600
122 if left$(ss$,4)="addx" then ad$=mid$(ss$,6):gosub 650
130 if st=0 then 110
140 close 1
155 print "strength =";ans
160 stop
600 rem noop
601 cyc=cyc+1
602 if rast=x-1 or rast=x or rast=x+1 then print "#";:goto 604
603 print " ";
604 rast=rast+1
605 if rast=40 then rast=0
610 if cyc=20 or cyc=60 or cyc=100 then ans=ans+(x*cyc)
611 if cyc=140 or cyc=180 or cyc=220 then ans=ans+(x*cyc)
612 return
650 rem addx
661 gosub 600
662 gosub 600
670 x=x+val(ad$)
680 return
run
