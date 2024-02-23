from django.urls import path
from . import views

urlpatterns=[
    path('',views.home,name='home'),
    path('metadata/',views.meta,name='metadata'),
    path('review/',views.review,name='review'),
    path('info/',views.info,name='info')
]