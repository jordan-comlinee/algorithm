import turtle


def draw_cat():
    # draw the body
    turtle.penup()
    turtle.goto(0, 0)
    turtle.pendown()
    turtle.circle(100)

    # draw the head
    turtle.penup()
    turtle.goto(0, 160)
    turtle.pendown()
    turtle.circle(40)

    # draw the legs
    turtle.penup()
    turtle.goto(-60, -50)
    turtle.pendown()
    turtle.right(30)
    turtle.forward(50)
    turtle.right(120)
    turtle.forward(50)
    turtle.right(120)
    turtle.forward(50)
    turtle.penup()
    turtle.goto(60, -50)
    turtle.pendown()
    turtle.left(30)
    turtle.forward(50)
    turtle.left(120)
    turtle.forward(50)
    turtle.left(120)
    turtle.forward(50)

    # draw the tail
    turtle.penup()
    turtle.goto(-80, -80)
    turtle.pendown()
    turtle.circle(20, 180)

    # draw the ears
    turtle.penup()
    turtle.goto(-40, 200)
    turtle.pendown()
    turtle.right(60)
    turtle.forward(30)
    turtle.right(120)
    turtle.forward(30)
    turtle.right(120)
    turtle.forward(30)
    turtle.penup()
    turtle.goto(40, 200)
    turtle.pendown()
    turtle.left(60)
    turtle.forward(30)
    turtle.left(120)
    turtle.forward(30)
    turtle.left(120)
    turtle.forward(30)

    # draw the eyes
    turtle.penup()
    turtle.goto(-20, 160)
    turtle.pendown()
    turtle.circle(10)
    turtle.penup()
    turtle.goto(20, 160)
    turtle.pendown()
    turtle.circle(10)


draw_cat()
turtle.done()