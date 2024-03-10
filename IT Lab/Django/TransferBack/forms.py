from django import forms

class TransferForm(forms.Form):
    SUBJECTS=[('Maths','Maths'),('Physics','Physics'),('English','English'),('Chemistry','Chemistry')]
    name=forms.CharField(widget=forms.TextInput)
    roll=forms.CharField(widget=forms.TextInput)
    subject=forms.ChoiceField(widget=forms.Select,choices=SUBJECTS)