new
10 data 3,0,3,7,3
20 data 2,5,5,1,2
30 data 6,5,3,3,2
40 data 3,3,5,4,9
50 data 3,5,3,9,0
60 dim grid(5,5)
70 for x=1 to 5
80 for y=1 to 5
90 read grid(x,y)
100 next y
110 next x
120 vis=0
130 for row=1 to 5
140 for col=1 to 5
160 if row=1 or row=5 goto 410
170 if col=1 or col=5 goto 410
230 xx=col-1
231 p1=1
240 for i1=xx to 1 step -1
250 if grid(row,i1)>=grid(row,col) then p1=0
260 next i1
270 xx=col+1
271 p2=1
280 for i2=xx to 5
290 if grid(row,i2)>=grid(row,col) then p2=0
300 next i2
310 xx=row-1
311 p3=1
320 for i3=xx to 1 step -1
330 if grid(i3,col)>=grid(row,col) then p3=0
340 next i3
350 xx=row+1
351 p4=1
360 for i4=xx to 5
370 if grid(i4,col)>=grid(row,col) then p4=0
380 next i4
399 if p1=1 or p2=1 or p3=1 or p4=1 goto 410
400 goto 430
410 vis=vis+1
430 next col
440 next row
450 print "visible =";vis
run
