from flask import Flask, render_template, request

app = Flask(__name__)

@app.route("/", methods=["GET", "POST"])
def index():
    if request.method == "GET":
        return render_template("index.html")
    elif request.method == "POST":
        return render_template("click.html", name=request.form.get("name", "world"))

# @app.route("/click", methods=["POST"])
# def click():
#     return render_template("click.html", name=request.args.get("name", "world"))

# alternative click.html
# @app.route("/click")
# def click():
#     name = request.args.get("name", "world")
#     return render_template("click.html", name=name)