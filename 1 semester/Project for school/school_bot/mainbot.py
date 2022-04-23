import json

import telebot
from telebot import types

with open("mainbot.config", "r") as read_file:
    global config
    config = json.load(read_file)


def data_base_init():
    global data_base
    data_base = {}
    data_base["replacement"] = open(config["replacement_path"] + config["replacement_file_name"], 'rb')
    markup = types.ReplyKeyboardMarkup(row_width=2, resize_keyboard=True)
    itembtn1 = types.KeyboardButton('расписание уроков')
    itembtn2 = types.KeyboardButton('расписание замен')
    markup.add(itembtn1, itembtn2)
    data_base["normal_keyboard"] = markup
    markup = types.ReplyKeyboardMarkup(row_width=4, resize_keyboard=True)
    for x in [["5А", "5Б", "5В"], ["6А", "6Б", "6В"], ["7А", "7Б", "7В"],
              ["8А", "8Б", "8В"], ["9А", "9Б", "9В", "9Г"], ["10А", "10Б", "11А", "11Б"]]:
        buf = []
        for y in x:
            buf.append(y)
        if len(buf) == 4:
            markup.add(buf[0], buf[1], buf[2], buf[3])
        else:
            markup.add(buf[0], buf[1], buf[2])
    data_base["chose_class_keyboard"] = markup


data_base_init()
bot = telebot.TeleBot(config["token"], parse_mode=None)


def send_timetable(message):
    bot.send_message(message.chat.id, "Выберите ваш класс", reply_markup=data_base["chose_class_keyboard"])

    @bot.message_handler(content_types=['text'])
    def message_input_step(message):
        text = message.text
        if not config["timetable_file_name"].get(text) is None:
            text = open(config["timetable_path"] + config["timetable_file_name"][text], 'r').readlines()
            string = ""
            for x in text:
                string += x
            bot.send_message(message.chat.id, string, reply_markup=data_base["normal_keyboard"])
        else:
            bot.send_message(message.chat.id, f"Нет такого класса: \"{text}\"",
                             reply_markup=data_base["normal_keyboard"])

    bot.register_next_step_handler(message, message_input_step)


def send_replacement(message):
    photo = open(config["replacement_path"] + config["replacement_file_name"], 'rb')
    bot.send_photo(message.chat.id, photo, reply_markup=data_base["normal_keyboard"])


@bot.message_handler(commands=['start'])
def send_welcome(message):
    bot.send_message(message.chat.id,
                     "Привет, ученик МБОУ СШ№1\n\n" +
                     "Этот бот создан чтобы ты мог узнать свое расписание не вставая со стула\n\n" +
                     "Бот не сохраняет и не обрататывает информацию о тебе\n\n" +
                     "Есни нужна помощь, нажми /help",
                     reply_markup=data_base["normal_keyboard"])


@bot.message_handler(commands=['help'])
def send_help(message):
    bot.send_message(message.chat.id,
                     "Если бот перестал работать попробуйте нажать /start\n\n" +
                     "Если остались вопросы, пишите на почту:\n" +
                     "SchoolNumberOneBot@gmail.com",
                     reply_markup=data_base["normal_keyboard"])


@bot.message_handler(content_types=['text'])
def sort_message(message):
    if message.text == "расписание замен":
        send_replacement(message)
    if message.text == "расписание уроков":
        send_timetable(message)


bot.infinity_polling()
