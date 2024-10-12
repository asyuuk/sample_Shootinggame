
x=255
y=300

function main()
  if  Func:moveLeft()=true then
    x=x-4;
elseif Func:moveRight()=true then
  x=x+4;
end
  if Func:moveUP()=true then
    y=y-4;
  elseif Func:moveDown()=true then
    y=y+4;
  end

end