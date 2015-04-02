package main

import "github.com/andlabs/ui"

var window ui.Window

func main() {
	go ui.Do(func() {
		name := ui.NewTextField()
		button := ui.NewButton("greet")
		greeting := ui.NewLabel("")

		stack := ui.NewVerticalStack(
			ui.NewLabel("name:"),
			name,
			button,
			greeting)

		window = ui.NewWindow("hello world", 200, 100, stack)

		button.OnClicked(func() {
			greeting.SetText("hello, " + name.Text() + "!")
		})

		window.OnClosing(func() bool {
			ui.Stop()
			return true
		})

		window.Show()
	})

	err := ui.Go()
	if err != nil {
		panic(err)
	}
}
